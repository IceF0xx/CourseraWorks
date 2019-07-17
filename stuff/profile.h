#pragma once
#include <iostream>


#define UNIQ_ID1(l) uniq_id_##l
#define UNIQ_ID(l) UNIQ_ID1(l)

#define LOG_DURATION(message)    \
    LogDuration UNIQ_ID(__LINE__) {message};

using namespace std;
using namespace std::chrono;

class LogDuration{
public:
    explicit LogDuration(const string& msg = "empty_message")
            : message(msg + ": "),
              start(steady_clock::now()) { }

    ~LogDuration() {
        auto end = steady_clock::now();
        auto duration = end - start;
        cerr << message << duration_cast<milliseconds>(duration).count()
             << " ms" << endl;
    }
private:
    const string message = "";
    const steady_clock::time_point start;
};