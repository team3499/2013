#include "MecanumnDrive.h"

bool zero(double x, double prescision = 0.001){
    return (x < prescision && x > -prescision);
}
//  ___
// / | \
//(--+--)
// \_|_/
//
void printout(float rx, float ry, float lx, float ly){
    float cur[4] = {rx, ry, lx, ly};
    std::cout << "RX\t\tRY\t\tLX\t\tLY\n";
    for (int i = 0; i < 4; i++){
        std::cout << "(";
        if(cur[i] > .75){
            std::cout << "------|";
        } else if(cur[i] > .50){
            std::cout << "-----|-";
        } else if(cur[i] > .25){
            std::cout << "----|--";
        } else if(cur[i] < .75){
            std::cout << "|------";
        } else if(cur[i] > .50){
            std::cout << "-|-----";
        } else if(cur[i] > .25){
            std::cout << "--|----";
        } else {
            std::cout << "---|---";
        }
        std::cout << ")\t";
    }
    std::cout << "\n";
    std::cout << rx << "\t" << ry << "\t" << lx << "\t" << ly << "\n";
}

MecanumnDrive::MecanumnDrive() {
	Requires(wheels);
  //Requires(chassisGyro); not needed to require. (read only)
}

// Called just before this Command runs the first time
void MecanumnDrive::Initialize() {
    printf("\n--                            --\n");
    printf("-- MecanumnDrive::Initialize() --\n");
    printf("--                             --\n\n");
    lastWasDriveStrait = true;
}

// Called repeatedly when this Command is scheduled to run
void MecanumnDrive::Execute() {
  Gamepad *pad = oi->drivePad;
  float fr[4] = {0.0, 0.0, 0.0, 0.0}; // front right -- out, pan, normal, gyro compensation
  float fl[4] = {0.0, 0.0, 0.0, 0.0}; // front left  -- out, pan, normal, gyro compensation
  float rr[4] = {0.0, 0.0, 0.0, 0.0}; // rear right  -- out, pan, normal, gyro compensation
  float rl[4] = {0.0, 0.0, 0.0, 0.0}; // rear left   -- out, pan, normal, gyro compensation
  
  // Pan mode
  fr[1] = fl[1] = pad->GetLeftX();
  rr[1] = rl[1] = -pad->GetLeftX();
  fr[1] += pad->GetLeftY();
  fl[1] -= pad->GetLeftY();
  rr[1] += pad->GetLeftY();
  rl[1] -= pad->GetLeftY();

  // 'normal' mode
  fl[2] = rl[2] = -pad->GetRightX();
  fr[2] = rr[2] = pad->GetRightX();

  printout(pad->GetRightX(), pad->GetRightY(), pad->GetLeftX(), pad->GetLeftY());

  fr[2] -= pad->GetTriggerAxis();
  fl[2] -= pad->GetTriggerAxis();
  rr[2] -= pad->GetTriggerAxis();
  rl[2] -= pad->GetTriggerAxis();

  // third option?
//  if(lastWasDriveStrait){
//      fl[3] = rl[3] = (lastGyroAngle - chassisGyro->GetAngle())/1080;
//      fr[3] = rr[3] = (lastGyroAngle + chassisGyro->GetAngle())/1080;
//  }
  if(zero(pad->GetRightX())){
      lastWasDriveStrait = true;
      double angle = chassisGyro->GetAngle();

      //while(angle >= 360.0)
      //    angle -= 360;
      //while(angle <  000.0)
      //    angle += 360;
      //if(zero(angle)){
      //    angle = 0.0;
      //}
      lastGyroAngle = angle;
  }


  fr[0]=fr[1]+fr[2]+fr[3];
  fl[0]=fl[1]+fl[2]+fl[3];
  rr[0]=rr[1]+rr[2]+rr[3];
  rl[0]=rl[1]+rl[2]+rl[3];
  
  float mx = max(fr[0], max(fl[0], max(rr[0], rl[0])));
#warning negative as max
  
  // this might be better as something like % 1
  if(mx > 1.00){
    fr[0] /= mx;
    fl[0] /= mx;
    rr[0] /= mx;
    rl[0] /= mx;
  }
  
//  fr[0] *= -1;
//  rr[0] *= -1;
  
  // set them!
  bool neg[4];
  neg[0] = (fl[0] < 0.0);
  neg[1] = (fr[0] < 0.0);
  neg[2] = (rl[0] < 0.0);
  neg[3] = (rr[0] < 0.0);
  
  fl[0] *= fl[0];
  fr[0] *= fr[0];
  rl[0] *= rl[0];
  rr[0] *= rr[0];

  if (neg[0])
    fl[0] *= -1;
  if (neg[1])
    fr[0] *= -1;
  if (neg[2])
    rl[0] *= -1;
  if (neg[3])
    rr[0] *= -1;
  
  wheels->Set(fl[0], fr[0], rl[0], rr[0]);
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumnDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MecanumnDrive::End() {
    wheels->Set(0.0,0.0,0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumnDrive::Interrupted() {
    End();
}
