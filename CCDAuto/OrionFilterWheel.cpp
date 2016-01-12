#include "stdafx.h"

using namespace System;
using namespace ASCOM;

#include "Form1.h"

namespace CCDAuto {


bool SetOrionFWPosition(int position) {

	bool success;

	success = SendOSUrobMessage('F', &position, NULL);

	return success;
}

bool GetOrionFWPosition(int *position) {

	bool success;

	success = SendOSUrobMessage('g', position, NULL);

	return success;
}



}