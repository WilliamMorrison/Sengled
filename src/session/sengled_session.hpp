#pragma once
#include <iostream>

class sengled_session {
public:
    sengled_session(bool persistance = false);
    void set_last_login(float login_time) { this->last_login_ = login_time; }
    void set_cookie(std::string ck) { this->cookie = ck; }

    float       get_last_login() { return this->last_login_; }
    std::string get_cookie() { return this->cookie; }

    bool is_session_valid();
    bool logged_in();

private:
    float last_login_ = 0.0;
    std::string cookie;
    // Session timeout is set to 24 hours
    const int SESSION_TIMEOUT = 60 * 60 * 24; 
};