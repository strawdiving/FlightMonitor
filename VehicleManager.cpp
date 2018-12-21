#include "VehicleManager.h"
#include "QuadApplication.h"
#include "linkmanager.h"
#include <QDebug>

VehicleManager::VehicleManager(QuadApplication *app)
    :ToolBase(app)
    , _linkMgr(NULL)
    , _activeVehicle(NULL)
{

}

VehicleManager::~VehicleManager()
{

}

void VehicleManager::setToolbox(Toolbox* toolbox)
{
    ToolBase::setToolbox(toolbox);
    _linkMgr = _toolbox->linkManager();

    connect(_linkMgr,&LinkManager::vehicleHeartbeatInfo,this,&VehicleManager::_vehicleHeartbeatInfo);
}

void VehicleManager::_vehicleHeartbeatInfo(SerialLink* link, int vehicleId)
{
    if(vehicleId == 0) {
        return;
    }

   if(_activeVehicle && _activeVehicle->id() == vehicleId) {
       //qDebug()<<"Vehicle already exists.";
       return;
    }

    Vehicle* vehicle = new Vehicle(link,vehicleId);
    if(vehicle) {
        qDebug()<<"vehicle created";
        _activeVehicle = vehicle;
        connect(vehicle,&Vehicle::linkDeleted,this,&VehicleManager::_deleteVehicle);

        emit activeVehicleChanged(_activeVehicle);
    }
}

void VehicleManager::_deleteVehicle(Vehicle* vehicle)
{
    if(_activeVehicle == vehicle) {
        _activeVehicle = NULL;
        emit activeVehicleChanged(_activeVehicle);
    }
}
