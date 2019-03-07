#pragma once

#include "date.h"

#include <list>
#include <map>

using namespace std;

class Database {
private:
    struct events_T {
        map<string, list<string>::iterator> sorted_events_;
        list<string> ordered_events_;
    };

    list<string>& GetOrderedEvents(map<Date, events_T>::iterator);
    const list<string>& GetOrderedEvents(map<Date, events_T>::const_iterator) const;

    map<string, list<string>::iterator>& GetSortedEvents(map<Date, events_T>::iterator);

public:
    Database();

    void Add(const Date& date, const string& event);

    void Print(ostream& os) const;

    template <class LambdaT>
    int RemoveIf(const LambdaT& predicate);

    template <class LambdaT>
    list<string> FindIf(const LambdaT& predicate) const;

    string Last(const Date& date) const;

private:
    map<Date, events_T> db_;
};

template <class LambdaT>
int Database :: RemoveIf(const LambdaT& predicate) {
    int deleted = 0;
    for (auto it = db_.begin(); it != db_.end(); ) {
        auto& date = it->first;
        auto& sorted_events = GetSortedEvents(it);
        for (auto event_it = sorted_events.begin(); event_it != sorted_events.end(); ) {
            const string& event = event_it->first;
            auto& remove_ordered_it = event_it->second;
            if (predicate (date, event)) {
                GetOrderedEvents(it).erase(remove_ordered_it);
                event_it = sorted_events.erase(event_it);
                ++deleted;
            } else {
                ++event_it;
            }
        }
        if (!sorted_events.size()) {
            it = db_.erase(it);
        } else {
            ++it;
        }
    }
    return deleted;
}

template <class LambdaT>
list<string> Database :: FindIf(const LambdaT& predicate) const {
    list<string> found;
    for (auto it = db_.begin(); it != db_.end(); ++it) {
        const Date& date = it->first;
        const auto& ordered_events = GetOrderedEvents(it);
        for (auto event_it = ordered_events.begin(); event_it != ordered_events.end(); ++event_it) {
            if (predicate(date, *event_it)) {
                found.emplace_back(date.DateStr() + ' ' + *event_it);
            }
        }
    }
    return found;
}