#include "StateGoWalk.h"
#include "KillerMain.h"

StateGoWalk::StateGoWalk(KillerMain* killerMainRef)
	: StateBase(killerMainRef)
{
	_moveFrequence = 7;
}

void StateGoWalk::OnEnter() {
	killerMainRef->MapManagerRef->KillerColor = GREEN;
}
//Move and avoid player room and adjacent
void StateGoWalk::Do() {
	if (killerMainRef->PlayerStepMemory % _moveFrequence == 0)
	{
		killerMainRef->KillerMovementRef->MoveKillerSafe(true);
	}
}

void StateGoWalk::OnExit() {
}