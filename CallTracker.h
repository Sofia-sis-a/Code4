#ifndef CALL_TRACKER_H
#define CALL_TRACKER_H

#include <iostream>

class CallTracker {
protected:
    char* subscriberName;       
    char* phoneNumber;          
    double maxCallDuration;     
    double minCallDuration;     
    double totalDuration;       
    int totalCalls;             

public:
    CallTracker(const char* phone, const char* name = nullptr);
    virtual ~CallTracker();

    double getMaxDuration() const;
    double getMinDuration() const;
    double getTotalDuration() const;
    int getTotalCalls() const;
    double getAverageDuration() const;
    bool isFrequentCommunication() const;

    virtual void addCall(double duration);
    virtual void printInfo() const;

    friend std::ostream& operator << (std::ostream& out, const CallTracker& ourObject);
    friend std::istream& operator >> (std::istream& in, CallTracker& ourObject);
};

double& operator += (double& sum, const CallTracker& ourObject);

#endif
