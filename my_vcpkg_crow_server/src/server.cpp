#include <crow.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/api/test").methods(crow::HTTPMethod::Post)
    ([](const crow::request& req) {
        try {
            auto req_json = json::parse(req.body);
            std::string name = req_json.value("name", "anonymous");
            int age = req_json.value("age", 0);

            json resp_json = {
                {"status", "ok"},
                {"message", "Hello, " + name},
                {"age_plus_one", age + 1}
            };

            return crow::response(200, resp_json.dump());
        } catch (...) {
            return crow::response(400, R"({"status":"error","message":"Invalid JSON"})");
        }
    });

    CROW_ROUTE(app, "/api/test2").methods(crow::HTTPMethod::Post)
    ([](const crow::request& req) {
        try {
            auto req_json = json::parse(req.body);
            std::string name = req_json.value("name", "anonymous");
            int age = req_json.value("age", 0);

            json resp_json = {
                {"status", "ok"},
                {"message", "Hello, " + name},
                {"age_plus_one", age + 1}
            };

            return crow::response(200, resp_json.dump());
        } catch (...) {
            return crow::response(400, R"({"status":"error","message":"Invalid JSON"})");
        }
    });

    std::cout << "Server running on http://localhost:18080/api/test" << std::endl;
    app.port(18080).multithreaded().run();
}

