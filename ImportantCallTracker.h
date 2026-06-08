#ifndef IMPORTANT_CALL_TRACKER_H
#define IMPORTANT_CALL_TRACKER_H

#include "CallTracker.h"

class ImportantCallTracker : public CallTracker {
private:
    double totalRating;
    double currentRating;

public:
    ImportantCallTracker(const char* phone, const char* name = nullptr);

    double getTotalRating() const;
    double getCurrentRating() const;
    double getAverageRating() const;

    void addCall(double duration, double rating);
    void printInfo() const override;
};

#endif
