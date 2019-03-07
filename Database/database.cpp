#include "database.h"

#include <algorithm>

Database :: Database() {
}

list<string>& Database :: GetOrderedEvents(map<Date, events_T>::iterator it) {
    return it->second.events_T::ordered_events_;
}

const list<string>& Database :: GetOrderedEvents(map<Date, events_T>::const_iterator it) const {
    return it->second.events_T::ordered_events_;
}

map<string, list<string>::iterator>& Database :: GetSortedEvents(map<Date, events_T>::iterator it) {
    return it->second.events_T::sorted_events_;
}

void Database :: Add(const Date& date, const string& event) {
    auto it = db_.find(date);
    if (it != db_.end()) {
        if (it->second.sorted_events_.count(event)) {
            return;
        }
    } else {
        it = db_.emplace(date, events_T()).first;
    }
    auto& ordered_events = GetOrderedEvents(it);
    auto ordered_it = ordered_events.emplace(ordered_events.end(), event);
    GetSortedEvents(it).emplace(event, ordered_it);
}

void Database :: Print(ostream& os) const {
    for (auto it = db_.begin(); it != db_.end(); ++it) {
        const Date& date = it->first;
        auto& ordered_events = GetOrderedEvents(it);
        for (const auto& ordered_event : ordered_events) {
            os << date << ' ' << ordered_event << endl;
        }
    }
}

string Database::Last(const Date& date) const {
    auto it = db_.upper_bound(date);
    if (it == db_.begin()) {
        return "No entries";
    }
    --it;
    return it->first.DateStr() + ' ' + GetOrderedEvents(it).back();
}
