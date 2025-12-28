#include "CLIApplication.h"

int main(int argc, char *argv[])
{
	auto& app = ppt::CLIApplication::instance(argc, argv);
	return app.execute();
}