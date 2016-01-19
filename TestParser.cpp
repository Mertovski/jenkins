#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "Parser.hpp"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestParser : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestParser);
	CPPUNIT_TEST(testsetPositions);
	CPPUNIT_TEST(testsetEvents);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp(void);
	void tearDown(void);

protected:
	void setPositions(void);
	void setEvents(void);

private:

	Parser *mTestObj;
};

//-----------------------------------------------------------------------------

void
TestParser::testsetPositions(void)
{
	CPPUNIT_ASSERT(2 == mTestObj->setPositions("b", 4));
}

void
TestParser::testsetEvents(void)
{
	CPPUNIT_ASSERT(0 == mTestObj->setEvents("a", 1));
}

void TestParser::setUp(void)
{
	mTestObj = new Parser();
}

void TestParser::tearDown(void)
{
	delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION(TestParser);

int main(int argc, char* argv[])
{
	// informs test-listener about testresults
	CPPUNIT_NS::TestResult testresult;

	// register listener for collecting the test-results
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener(&collectedresults);

	// register listener for per-test progress output
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener(&progress);

	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);

	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write();

	// Output XML for Jenkins CPPunit plugin
	ofstream xmlFileOut("cppTestPARSERhResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}