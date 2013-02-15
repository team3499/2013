#include "MecanumnDrive.h"

MecanumnDrive::MecanumnDrive() {
	// Use Requires() here to declare subsystem dependencies
	Requires(wheels);
}

// Called just before this Command runs the first time
void MecanumnDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void MecanumnDrive::Execute() {
	Gamepad *pad = oi->drivePad;
	float fr[4] = {0.0, 0.0, 0.0, 0.0}; // front right
	float fl[4] = {0.0, 0.0, 0.0, 0.0}; // front left
  float rr[4] = {0.0, 0.0, 0.0, 0.0}; // rear right
  float rl[4] = {0.0, 0.0, 0.0, 0.0}; // rear left
  
  // Left wheels go left going forward , back.
  // right wheels go 
  
  
  // Pan mode
  fr[1] = fl[1] = -pad->GetLeftX();
  rr[1] = rl[1] = pad->GetLeftX();
  fr[1] += pad->GetLeftY();
  fl[1] += pad->GetLeftY();
  rr[1] += pad->GetLeftY();
  rl[1] += pad->GetLeftY();
	  // 'normal' mode
  fl[2] = rl[2] = pad->GetRightX();
  fr[2] = rr[2] = -pad->GetRightX();
  fr[2] += pad->GetRightY();
  fl[2] += pad->GetRightY();
  rr[2] += pad->GetRightY();
  rl[2] += pad->GetRightY();
	  // third option?
  
  fr[0]=fr[1]+fr[2]+fr[3];
  fl[0]=fl[1]+fl[2]+fl[3];
  rr[0]=rr[1]+rr[2]+rr[3];
  rl[0]=rl[1]+rl[2]+rl[3];
  
  float mx = max(fr[0], max(fl[0], max(rr[0], rl[0])));
  
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
  
  if (neg[0]) // Invert these
    fl[0] *= -1;
  if (!neg[1])
    fr[0] *= -1;
  if (neg[2]) // Invert these
    rl[0] *= -1;
  if (!neg[3])
    rr[0] *= -1;
  
  wheels->Set(fl[0], fr[0], rl[0], rr[0]);
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumnDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MecanumnDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumnDrive::Interrupted() {
}
