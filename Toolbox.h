#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QObject>

class LinkManager;
class VehicleManager;
class QuadApplication;

class Toolbox
{
public:
    Toolbox(QuadApplication* app);
    ~Toolbox();
    LinkManager* linkManager(void) { return _linkMgr;}
    VehicleManager* vehicleManager(void) { return _vehicleMgr;}

   private:
    LinkManager* _linkMgr;
    VehicleManager* _vehicleMgr;
};

class ToolBase : public QObject
{
    Q_OBJECT
public:
    ToolBase(QuadApplication* app);

    virtual void setToolbox(Toolbox* toolbox);

protected:
    QuadApplication* _app;
    Toolbox* _toolbox;
};

#endif // TOOLBOX_H
