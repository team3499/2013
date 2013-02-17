#include <QtCore/QtCore>
#include <QDebug>
#include <QDir>
#include <QStringList>
#include <iostream>

//#define BASE "C:/Users/Charlie Waters/XENEZ/FIRST-13/2013"

void writeover(FILE *f, FILE *fdo);

int main(int argc, char *argv[]){

    QStringList list;
    QStringList dirlist;

    dirlist << "C:/WindRiver/workspace/2013";

    QStringList dlist = QDir("C:/WindRiver/workspace/2013", "*.cpp").entryList(); // Get all source files in the project folder
    while(!dlist.empty()){
        QString file = QString("%1/%2").arg("C:/WindRiver/workspace/2013").arg(dlist.takeLast()); // need to add on the first part of file directory name
        file = file.right(file.length()-28);
        file.chop(4);
        list += file; // remove constant filename prefix, and suffix
    }

    QDirIterator directories("C:/WindRiver/workspace/2013", QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);

    while(directories.hasNext()){
        directories.next();
        if(!directories.filePath().startsWith("C:/WindRiver/workspace/2013/Deploy", Qt::CaseInsensitive)){
            QString path = directories.filePath();

            QDir projectDir( path, "*.cpp");
            QStringList nlist = projectDir.entryList();

            while(!nlist.empty()){
                QString file = QString("%1/%2").arg(path).arg(nlist.takeLast()); // need to add on the first part of file directory name
                file = file.right(file.length()-28); // remove constant filename prefix
                file.chop(4); // remove suffix
                list += file;
            }

            dirlist.append(path);
        }
    }

    qDebug() << list;
    qDebug() << dirlist;

    if(list.empty()){
        std::cout << "Error: No .cpp files to compile!\n";
        exit(-2);
    }

    unlink("Makefile"); // remove if it exists.
    FILE *f = fopen("Makefile", "w"); // open to write

    FILE *fdp1 = fopen("mkp1", "r"); // open to read
    FILE *fdp2 = fopen("mkp2", "r");
    FILE *fdp3 = fopen("mkp3", "r");

    if(f == NULL || fdp1 == NULL || fdp2 == NULL || fdp3 == NULL){
        std::cout << "opening failed :(\n";
        exit(-3);
    }


    /////// WRITING ////////

    // Write first part. There are project specific settings here, ie. project root folder
    writeover(f, fdp1);

    QStringList tlist = list;
    while(!tlist.empty()){
        QString fl = tlist.takeLast();
        fprintf(f, "2013_partialImage/$(MODE_DIR)/Objects/2013/%s.o : $(PRJ_ROOT_DIR)/%s.cpp $(FORCE_FILE_BUILD)\n", fl.toStdString().c_str(), fl.toStdString().c_str());
        fprintf(f, "\t$(TRACE_FLAG)if [ ! -d \"`dirname \"$@\"`\" ]; then mkdir -p \"`dirname \"$@\"`\"; fi;echo \"building $@\"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o \"$@\" -c \"$<\"\n\n\n");
    }

    tlist = list;
    if(!tlist.empty()){
        QString fl = tlist.takeLast();
        fprintf(f, "OBJECTS_2013_partialImage = 2013_partialImage/$(MODE_DIR)/Objects/2013/%s.o ", fl.toStdString().c_str());
    }

    while(!tlist.empty()){
        QString fl = tlist.takeLast();
        fprintf(f, " \\\n\t2013_partialImage/$(MODE_DIR)/Objects/2013/%s.o ", fl.toStdString().c_str());
    }
    fprintf(f, "\n\n");

    // Write second consistent part
    writeover(f, fdp2);

    tlist = list;
    if(!tlist.empty()){
        QString fl = tlist.takeLast();
        fprintf(f, "DEP_FILES := 2013_partialImage/$(MODE_DIR)/Objects/2013/%s.d ", fl.toStdString().c_str());
    }

    while(!tlist.empty()){
        QString fl = tlist.takeLast();
        fprintf(f, " \\\n\t2013_partialImage/$(MODE_DIR)/Objects/2013/%s.d ", fl.toStdString().c_str());
    }

    // Write the last part
    writeover(f, fdp3);

    return 0;
}

// Write from file descriptor of original over to fd of new makefile
void writeover(FILE *f, FILE *fdo){
    while(!feof(fdo)){
        char c = fgetc(fdo);
        if(c != 'ÿ')
            fputc(c, f);
        else
            qDebug() << "Found invalid character \'ÿ\'\n";
    }
}
