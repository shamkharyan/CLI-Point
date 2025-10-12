#include "model/PPModel.h"
#include "model/AppContext.h"

PPModel& PPModel::instance()
{
	static PPModel obj;
	return obj;
}

AppContext& PPModel::getContext()
{
	return m_context;
}