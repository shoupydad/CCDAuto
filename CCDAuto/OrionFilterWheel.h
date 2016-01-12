#pragma once

using namespace System;
using namespace ASCOM;

namespace CCDAuto {


	public ref class OrionFilterWheel : public System::Object {

	public:
		static OrionFilterWheel ^Ptr;
		static ASCOM::Nautilus::FilterWheel ^FilterWheel;
		static int MaxPosition, MinPosition;
		OrionFilterWheel(void);
		~OrionFilterWheel(void);
	};

}