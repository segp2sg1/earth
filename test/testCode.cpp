//  Copyright (C) 2001-2003 Matthew Landauer. All Rights Reserved.
//  
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of version 2 of the GNU General Public License as
//  published by the Free Software Foundation.
//
//  This program is distributed in the hope that it would be useful, but
//  WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  Further, any
//  license provided herein, whether implied or otherwise, is limited to
//  this program in accordance with the express provisions of the GNU
//  General Public License.  Patent licenses, if any, provided herein do not
//  apply to combinations of this program with other product or programs, or
//  any other product whatsoever.  This program is distributed without any
//  warranty that the program is delivered free of the rightful claim of any
//  third person by way of infringement or the like.  See the GNU General
//  Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program; if not, write the Free Software Foundation, Inc., 59
//  Temple Place - Suite 330, Boston MA 02111-1307, USA.
//
// $Id$

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestListener.h>
#include <cppunit/Test.h>
#include <cppunit/TestResult.h>

#include "ImageFormat.h"

class MyProgressTestListener : public CppUnit::TestListener
{
public:
	virtual void startTest(CppUnit::Test *test)
	{
		std::cout << "Starting " << test->getName() << std::endl;
	}
};

int main(int argc, char **argv)
{
	// Register the plugins
	Sp::ImageFormat::registerPlugins();

	CppUnit::TextUi::TestRunner runner;

	// Retrieve the instance of the TestFactoryRegistry
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();

	// Obtain and add a new TestSuite created by the TestFactoryRegistry that contains all
	// the test suite registered using CPPUNIT_TEST_SUITE_REGISTRATION().
	runner.addTest( registry.makeTest() );
	//runner.setOutputter(CppUnit::CompilerOutputter::defaultOutputter(&runner.result(), std::cerr));
	
	// Add an extra test progress listener if we want a more verbose ouput
	MyProgressTestListener progress;
 	runner.eventManager().addListener( &progress );
 	
 	runner.run();
	
	Sp::ImageFormat::deRegisterPlugins();
	return 0;
}

