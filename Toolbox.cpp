#include "Toolbox.h"
#include "linkmanager.h"
#include "VehicleManager.h"

Toolbox::Toolbox(QuadApplication *app)
    :_linkMgr(NULL)
    , _vehicleMgr(NULL)
{
    _linkMgr = new LinkManager(app);
    _vehicleMgr = new VehicleManager(app);

    _linkMgr->setToolbox(this);
    _vehicleMgr->setToolbox(this);
}

Toolbox::~Toolbox()
{
    delete _linkMgr;
    delete _vehicleMgr;
}

ToolBase::ToolBase(QuadApplication* app)
    :QObject((QObject*) app)
    , _app(app)
    , _toolbox(NULL)
{

}

void ToolBase::setToolbox(Toolbox* toolbox)
{
    _toolbox = toolbox;
}
