#include <algorithm>

#include <catch2/catch_all.hpp>

#include <json_type.hpp>

class JsonFixture {
   public:
    JsonType::object obj;
    JsonFixture() : obj{} {
        obj["list"] = JsonType::list{{"str", 2}};
        auto obj_obj = JsonType::object();
        obj_obj["a"] = 0.5;
        obj["obj"] = obj_obj;
        obj["int"] = 1;
        obj["double"] = 0.1;
        obj["bool"] = true;
        // obj["null"] = JsonType::null;
        obj["str"] = "string";
    }
};

TEST_CASE("Test value assignment", "[unit]") {
    JsonType::json_type json_obj;
    CHECK_NOTHROW(json_obj = JsonType::object());
    CHECK_NOTHROW(json_obj = JsonType::list());
    CHECK_NOTHROW(json_obj = 1);
    CHECK_NOTHROW(json_obj = 0.1);
    CHECK_NOTHROW(json_obj = true);
    // CHECK_NOTHROW(json_obj = JsonType::null);
    CHECK_NOTHROW(json_obj = "string");
}

TEST_CASE("Test list emplace", "[unit]") {
    JsonType::list list;
    CHECK_NOTHROW(list.emplace_back(JsonType::object()));
    CHECK_NOTHROW(list.emplace_back(JsonType::list()));
    CHECK_NOTHROW(list.emplace_back(1));
    CHECK_NOTHROW(list.emplace_back(0.1));
    CHECK_NOTHROW(list.emplace_back(true));
    // CHECK_NOTHROW(list.emplace_back(JsonType::null));
    CHECK_NOTHROW(list.emplace_back("string"));
}

TEST_CASE("Test object assign", "[unit]") {
    JsonType::object obj;
    CHECK_NOTHROW(obj["list"] = JsonType::list());
    CHECK_NOTHROW(obj["obj"] = JsonType::object());
    CHECK_NOTHROW(obj["int"] = 1);
    CHECK_NOTHROW(obj["double"] = 0.1);
    CHECK_NOTHROW(obj["bool"] = true);
    // CHECK_NOTHROW(obj["null"] = JsonType::null);
    CHECK_NOTHROW(obj["str"] = "string");
}

TEST_CASE_METHOD(JsonFixture, "Test manipulation") {
    CHECK(obj.size() == 6);
    SECTION("Change value") {
        CHECK(std::holds_alternative<int>(obj["int"]));
        CHECK_NOTHROW(obj["int"] = 0.2);
        CHECK(std::holds_alternative<double>(obj["int"]));
    }
}

TEST_CASE_METHOD(JsonFixture, "Test get") {
    int int_val;
    REQUIRE(obj.contains("int"));
    CHECK_NOTHROW(int_val = std::get<int>(obj["int"]));
    CHECK(int_val == 1);
}

TEST_CASE_METHOD(JsonFixture, "Test delete") {
    REQUIRE(obj.contains("int"));
    CHECK_NOTHROW(obj.erase("int"));
    CHECK(!obj.contains("int"));
}

TEST_CASE_METHOD(JsonFixture, "Test iteration") {
    JsonType::list list;
    REQUIRE(obj.contains("list"));
    CHECK_NOTHROW(list = std::get<JsonType::list>(obj["list"]));
    for (int indx = 0; auto const& item : list) {
        if (indx == 0) {
            CHECK(std::holds_alternative<std::string>(item));
            CHECK(item == JsonType::json_type("str"));
        } else if (indx == 1) {
            CHECK(std::holds_alternative<int>(item));
            CHECK(item == JsonType::json_type(2));
        }
        indx++;
    }
}
