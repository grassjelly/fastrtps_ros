// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file VelocitiesPubSubMain.cpp
 * This file acts as a main entry point to the application.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include "VelocitiesPublisher.h"
#include "VelocitiesSubscriber.h"


#include <fastrtps/Domain.h>

using namespace eprosima;
using namespace eprosima::fastrtps;

int main(int argc, char** argv)
{
	cout << "Starting " << endl;
	int type = 1;
	if (argc > 1)
	{
		if (strcmp(argv[1], "r2d") == 0)
		{
			type = 1;
		}
		else if (strcmp(argv[1], "d2r") == 0)
		{
			type = 2;
		}
	}
	else
	{
		cout << "publisher OR subscriber argument needed" << endl;
		return 0;
	}
	
	// Register the type being used
	
	
	switch(type)
	{
		case 1:
		{
			VelocitiesPublisher mypub;
			if (mypub.init())
			{
				ros::init(argc,argv, "ros_dds_bridge");
				mypub.run();
			}
			break;
		}
		case 2:
		{
			VelocitiesSubscriber mysub;
			if (mysub.init())
			{
				ros::init(argc,argv, "dds_ros_bridge");
				mysub.run();
			}
			break;
		}
	}
	
	return 0;
}
