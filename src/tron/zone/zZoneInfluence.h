#ifndef ArmageTron_ZoneInfluence_H
#define ArmageTron_ZoneInfluence_H

#include <boost/shared_ptr.hpp>
#include <vector>
#include "defs.h"
#include "eCoord.h"
#include "tSafePTR.h"
#include "rColor.h"

class zZone;
//typedef boost::shared_ptr< zZone > zZonePtr;
typedef tJUST_CONTROLLED_PTR< zZone> zZonePtr;
//typedef zZone * zZonePtr;

class zZoneInfluenceItem;
typedef boost::shared_ptr<zZoneInfluenceItem> zZoneInfluenceItemPtr;
typedef std::vector<zZoneInfluenceItemPtr> zZoneInfluenceItemList;

class zZoneInfluence {
protected:
    zZonePtr zone;
    zZoneInfluenceItemList zoneInfluenceItems;

public:
    zZoneInfluence(zZonePtr _zone);
    ~zZoneInfluence();
    void apply(REAL value);

    void addZoneInfluenceRule(zZoneInfluenceItemPtr aRule) {zoneInfluenceItems.push_back(aRule);};
};

class zZoneInfluenceItem {
protected:
    zZonePtr zone;
public:
    zZoneInfluenceItem(zZonePtr aZone);
    virtual ~zZoneInfluenceItem();

    virtual void apply(REAL value) {};
};

class zZoneInfluenceItemRotation : public zZoneInfluenceItem {
protected:
    REAL rotationSpeed;
    REAL rotationAcceleration;
public:
    zZoneInfluenceItemRotation(zZonePtr aZone);
    virtual ~zZoneInfluenceItemRotation() {};

    void set(REAL rotSp, REAL rotAcc) {rotationSpeed = rotSp; rotationAcceleration = rotAcc;};
    virtual void apply(REAL value);
};

class zZoneInfluenceItemRadius : public zZoneInfluenceItem {
protected:
    REAL radius;
public:
    zZoneInfluenceItemRadius(zZonePtr aZone);
    virtual ~zZoneInfluenceItemRadius() {};

    void set(REAL rad) {radius = rad;};
    virtual void apply(REAL value);
};

class zZoneInfluenceItemPosition : public zZoneInfluenceItem {
protected:
    eCoord pos;
public:
    zZoneInfluenceItemPosition(zZonePtr aZone);
    virtual ~zZoneInfluenceItemPosition() {};

    void set(eCoord const & p) {pos = p;};
    virtual void apply(REAL value);
};

class zZoneInfluenceItemColor : public zZoneInfluenceItem {
protected:
    rColor color;
public:
    zZoneInfluenceItemColor(zZonePtr aZone);
    virtual ~zZoneInfluenceItemColor() {};

    void set(rColor const & col) {color = col;};
    virtual void apply(REAL value);
};

#include "zZone.h"

#endif
