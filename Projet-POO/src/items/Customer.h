#pragma once
#include "Addresse.h"

using namespace System;
using namespace Collections;
using namespace Generic;

class User
{
	public:
		String^ firstName;
		String^ lastName;
		DateTime^ birthDate;
		List<Addresse^>^ addresses;
};
