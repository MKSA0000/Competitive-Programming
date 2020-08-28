#include"INCLUDES.h"

bool bysecond(const vi& lhs, const vi& rhs) {
    if (lhs[1] != rhs[1]) {
        return lhs[1] > rhs[1];
    }
    else {
        return lhs[0] > rhs[0];
    }

}

bool byfirst(const vi& lhs, const vi& rhs) {
    if (lhs[0] != rhs[0]) {
        return lhs[0] > rhs[0];
    }
    else {
        return lhs[1] > rhs[1];
    }
}


bool byfifth(const vi& lhs, const vi& rhs) {
    if (lhs[4] != rhs[4]) {
        return lhs[4] < rhs[4];
    }
    else {
        return lhs[0] > rhs[0];
    }
}