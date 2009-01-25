/*
 * sensor.h
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2008-12-10.
 * Copyright 2008 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

/*
 * TODO: Debugging using qDebug()
 */

#ifndef SENSOR_H
#define SENSOR_H

#include "../core.h"

#include <QString>

class Sensor : public Core {
public:
    enum FrequencyType {Hz, MHz, Ghz};

    Sensor(const QString &_name, quint8 _id, quint32 _range, quint8 _accuracy,
           quint32 frequency, Sensor::FrequencyType freqType=Hz);
    virtual ~Sensor();

    /*
     * It turns on and off the object actions
     *
     * Returns true if it worked properly, false otherwise
     */
    bool turnOn();
    bool turnOff();

    quint32 getRange() const;
    void setRange(quint32 _range);

    quint32 getFrequency() const;
    void setFrequency(quint32 _frequency);

    quint8 gettAccuracy() const;
    void setAccuracy(quint8 _accuracy);

    Sensor::FrequencyType getFreqType() const;
    void setFreqType(Sensor::FrequencyType _freqType);

    /*
     * Abstract virtual functions that the child will inherit and do whatever
     * they want to their functionality when the object will start and stop
     */
    virtual void start() = 0;
    virtual void stop() = 0;

private:
    quint32 range;
    quint32 frequency;
    quint8 accuracy;
    Sensor::FrequencyType freqType;
};

#endif // SENSOR_H
