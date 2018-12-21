/**
 * @file
 *   @brief Class Vehicle. This class represents a vehicle with specific id, it handles received messages
 *  sent from LinkManager instance, decodes and parses messages and then dispatchs parsed valid information.
 *
 */
#ifndef VEHICLE_H
#define VEHICLE_H

#include <QObject>
#include <common/mavlink.h>
#include "SerialCommunication.h"
#include <QVariant>
#include <mavlink_types.h>

class Vehicle;
class LinkManager;
class UAS;

class Vehicle : public QObject
{
    Q_OBJECT
public:
    explicit Vehicle(SerialLink* link, int vehicleId);
    ~Vehicle();

    /// all called by vihicle when used afterwards
    LinkManager* linkManager(void) { return _linkMgr;}

    int id(void) { return _vehicleId;}

private:
    QString _flightMode(uint8_t baseMode);  /// string of current flight mode
    void _addLink(SerialLink* link);
    void _handleHeartbeat(mavlink_message_t& message);  /// handle heartbeat message

    LinkManager * _linkMgr;
    SerialLink* _link;

    int                     _vehicleId;  /// system id of current vehicle
    uint8_t             _base_mode;   /// custom flight modes, 2-manual, 3- altitude, 3-position
    uint32_t           _armed;
    int8_t               _system_status;

signals:
    /// signal to VehicleManager to handle link deletion
    void linkDeleted(Vehicle* vehicle);

    /// emit to mainWindow to show status of flight
    void modeChanged(QString shortModeText);
    void telemetryChanged(uint8_t rssi);
    void attitudeChanged(mavlink_attitude_t* attitude);
    void altitudeChanged(float pressure_alt);
    void batteryChanged(int8_t voltage_battery);
    void GPSStatusChanged(mavlink_gps_raw_int_t* gps_raw_int);
    void globalPositionChanged(mavlink_global_position_int_t* global_position_int);
    void localPositionChanged(mavlink_local_position_ned_t* local_position);
    void groundSpeedChanged(float);
    void statusChanged(uint8_t status);
    void armedChanged(uint32_t);

public slots:
    void _linkDeleted(SerialLink* link);
    /// Handle messages from LinkManager, parse status of vehicle and flight
    void _mavlinkMessageReceived(SerialLink*link, mavlink_message_t &message);
};

#endif // VEHICLE_H
