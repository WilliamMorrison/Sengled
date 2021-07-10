#include "sengled_session.hpp"
#include <boost/filesystem.hpp>
#include <nlohmann/json.hpp>
#include <iomanip>

sengled_session::sengled_session(bool persistance){
    if(persistance){
        //check if file exists in application path
        if(!boost::filesystem::exists("src/persistance/persistant_session.json")){
            // file does not exist - create it
            std::ofstream persistant_file("src/persistance/persistant_session.json");
            nlohmann::json file_contents = {{"cookie", ""}, {"last_login", "0.0"}};

            // output/make the json contents pretty
            persistant_file << std::setw(4) << file_contents;
            persistant_file.close();
        }
        else{
            // file exists / load it into the session
            std::ifstream input_file("src/persistance/persistant_session.json");
            nlohmann::json session_json = nlohmann::json::parse(input_file);

            set_cookie(session_json["cookie"]);
            set_last_login(session_json["last_login"]);
        }
    }
}

