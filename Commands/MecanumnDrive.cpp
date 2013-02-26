#include "MecanumnDrive.h"

bool zero(double x, double prescision = 0.001){
    return (x < prescision && x > -prescision);
}

float absf(float x){
    return x < 0.0 ? -x : x;
}

float maxf(float x, float y){
    return x > y ? x : y;
}

//  ___
// / | \
//(--+--)
// \_|_/
//
void printout(float rx, float ry, float lx, float ly, float trig){

    //std::cout << "    ___      ___      ___      ___" << std::endl;
    //std::cout << "   / | \    / | \    / | \    / | \" << std::endl;
    //std::cout << "  (--+--)  (--+--)  (--+--)  (--+--)   (--+--)" << std::endl;
    //std::cout << "   \_|_/    \_|_/    \_|_/    \_|_/" << std::endl;
    //    ___      ___      ___      ___
    //   / | \    / | \    / | \    / | \
    //  (--+--)  (--+--)  (--+--)  (--+--)   (--+--)
    //   \_|_/    \_|_/    \_|_/    \_|_/


    //std::cout << "Drive: left (" << lx << "," << ly << ") right (" << rx << "," << ry << ") trigger " << trig << std::endl;
    printf("Drive: left (%.6f,%.6f) right (%.6f,%.6f) trigger %.6f\n", lx, ly, rx, ry, trig);
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
  float fr[3] = {0.0, 0.0, 0.0}; // front right -- out, pan, normal, gyro compensation
  float fl[3] = {0.0, 0.0, 0.0}; // front left  -- out, pan, normal, gyro compensation
  float rr[3] = {0.0, 0.0, 0.0}; // rear right  -- out, pan, normal, gyro compensation
  float rl[3] = {0.0, 0.0, 0.0}; // rear left   -- out, pan, normal, gyro compensation
  
  // Pan mode
  fr[1] = fl[1] = pad->GetRightX();
  rr[1] = rl[1] = -pad->GetRightX();
  fr[1] += pad->GetRightY();
  fl[1] -= pad->GetRightY();
  rr[1] += pad->GetRightY();
  rl[1] -= pad->GetRightY();

  // 'normal' mode
  fl[2] = rl[2] = pad->GetLeftX();
  fr[2] = rr[2] = pad->GetLeftX();

  fr[2] += pad->GetTriggerAxis();
  fl[2] -= pad->GetTriggerAxis();
  rr[2] += pad->GetTriggerAxis();
  rl[2] -= pad->GetTriggerAxis();

  fr[0]=fr[1]+fr[2];
  fl[0]=fl[1]+fl[2];
  rr[0]=rr[1]+rr[2];
  rl[0]=rl[1]+rl[2];
  
  float mx = maxf(absf(fr[0]), absf(maxf(absf(fl[0]), absf(maxf(absf(rr[0]), absf(rl[0]))))));
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

//  if(zero(fl[0]), .01)
//      fl[0] = 0.0;
//  if(zero(fr[0]), .01)
//      fr[0] = 0.0;
//  if(zero(rl[0]), .01)
//      rl[0] = 0.0;
//  if(zero(rr[0]), .01)
//      rr[0] = 0.0;
  
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
