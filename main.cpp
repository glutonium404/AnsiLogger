#include "includes/AnsiLogger.hpp"
#include <string>
#include <type_traits>
#include <utility>

// example of how you can extend the class to then create your own methods or just write simple helper function
class MyLogger : public AnsiLogger {
public:
    using AnsiLogger::AnsiLogger;

    template<typename F, typename S>
    AnsiLogger pair(std::pair<F, S>& pair) const {
        std::string key, value;

        if constexpr (! std::is_same_v<F, std::string>) {
            key = std::to_string(pair.first);
        }else {
            key = pair.first;
        }

        if constexpr (! std::is_same_v<S, std::string>) {
            value = std::to_string(pair.second);
        }else {
            value = pair.second;
        }

        return AnsiLogger::bg_cyan(AnsiLogger::black("KEY : VALUE")).new_line(1).reverse(AnsiLogger::tag(key, value));
    }
};

int main() {
    std::pair<std::string, int> p = {"MyLogger", 420};
    MyLogger ml;
    ml.pair(p).new_line(3).to_cout();

    AnsiLogger::has_nerd_font = true;
    AnsiLogger logger;

    logger
        .italic(
            logger
            .bg_magenta(logger.blue("my"))
            .space(2)
            .yellow("name ")
            .red("is ")
            .green("meow ")
            .cyan("meow")
        )
        .tab(2)
        .append("hi")
        .tab(2)
        .dim(
            logger
            .bg_magenta(logger.blue("my"))
            .space(2)
            .yellow("name ")
            .red("is ")
            .green("meow ")
            .cyan("meow")
        )
        .new_line(2)
        .to_cout();

    logger
        .italic(
            logger
            .log("SYSTEM DIAGNOSTICS INITIALIZED")
            .new_line(2)
            .warning("The system has detected a significant discrepancy between the expected sensor input values and the actual telemetry data received from the auxiliary cooling units, which could lead to an overheating event if the current workload is not throttled immediately across all processing nodes.")
            .new_line(2)
            .error("A critical memory corruption event was identified at memory address 0x004F3A during the execution of the high-level garbage collection routine, resulting in an irreversible state inconsistency that demands an immediate process termination and a full manual hardware reset to prevent data loss.")
        )
        .new_line(3)
        .success("Success").new_line()
        .debug("Debug").new_line()
        .info("Info").new_line()
        .trace("Trace").new_line()
        .tag("key", "value")
        .to_cout();
}
