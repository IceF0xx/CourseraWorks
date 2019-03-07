#pragma once

#include "date.h"

#include <memory>

using namespace std;

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

enum class LogicalOperation {
    Or,
    And,
};

class Node {
public:
    Node();

    virtual ~Node();

    virtual const bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
    EmptyNode();

    const bool Evaluate(const Date& db_date, const string& db_event) const override;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& logic_op, const shared_ptr<Node>& left, const shared_ptr<Node>& right);

    const bool Evaluate(const Date& db_date, const string& db_event) const override;

private:
    const LogicalOperation logic_op_;
    const shared_ptr<Node> lhs_;
    const shared_ptr<Node> rhs_;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& cmp, const Date& date);

    const bool Evaluate(const Date& db_date, const string& db_event) const override;

private:
    const Comparison cmp_;
    const Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& cmp, const string& event);

    const bool Evaluate(const Date& db_date, const string& db_event) const override;

private:
    const Comparison cmp_;
    const string event_;
};