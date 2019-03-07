#include "node.h"

template <typename T>
const bool Compare(const T& lhs, const Comparison& cmp, const T& rhs) {
    switch (cmp) {
        case Comparison::Less:
            return lhs < rhs;
        case Comparison::LessOrEqual:
            return lhs <= rhs;
        case Comparison::Equal:
            return lhs == rhs;
        case Comparison::NotEqual:
            return lhs != rhs;
        case Comparison::GreaterOrEqual:
            return lhs >= rhs;
        case Comparison::Greater:
            return lhs > rhs;
    }
    return false;
}

Node :: Node() {
}

Node :: ~Node() {
}

EmptyNode :: EmptyNode() {
}

const bool EmptyNode :: Evaluate(const Date& db_date, const string& db_event) const {
    return true;
}

DateComparisonNode :: DateComparisonNode(const Comparison& cmp, const Date& date) : cmp_(cmp), date_(date) {
}

const bool DateComparisonNode :: Evaluate(const Date& db_date, const string& db_event) const {
    return Compare(db_date.DateVal(), cmp_, date_.DateVal());
}

EventComparisonNode :: EventComparisonNode(const Comparison& cmp, const string& event) : cmp_(cmp), event_(event) {
}

const bool EventComparisonNode :: Evaluate(const Date& db_date, const string& db_event) const {
    return Compare(db_event, cmp_, event_);
}

LogicalOperationNode :: LogicalOperationNode(const LogicalOperation& logic_op, const shared_ptr<Node>& left, const shared_ptr<Node>& right) :
        logic_op_(logic_op), lhs_(left), rhs_(right) {
}

const bool LogicalOperationNode :: Evaluate(const Date& db_date, const string& db_event) const {
    const bool lhs_evt = lhs_->Evaluate(db_date, db_event);
    const bool rhs_evt = rhs_->Evaluate(db_date, db_event);
    switch (logic_op_) {
        case LogicalOperation::And:
            return lhs_evt && rhs_evt;
        case LogicalOperation::Or:
            return lhs_evt || rhs_evt;
    }
    return false;
}