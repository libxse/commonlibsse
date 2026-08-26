#include "RE/M/MenuEventHandler.h"

namespace RE
{
	bool MenuEventHandler::ProcessMotionGesture(MotionGestureEvent*)
	{
		return false;
	}

	bool MenuEventHandler::ProcessSixaxis(SixaxisEvent*)
	{
		return false;
	}

	bool MenuEventHandler::ProcessKinect(KinectEvent*)
	{
		return false;
	}

	bool MenuEventHandler::ProcessThumbstick(ThumbstickEvent*)
	{
		return false;
	}

	bool MenuEventHandler::ProcessMouseMove(MouseMoveEvent*)
	{
		return false;
	}

	bool MenuEventHandler::ProcessButton(RE::ButtonEvent*)
	{
		return false;
	}
}
