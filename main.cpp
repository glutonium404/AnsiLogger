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
    AnsiLogger::has_nerd_font = true;
    AnsiLogger logger;

    logger.bold(logger.cyan("AnsiLogger showcase")).new_line(2).to_cout();

    logger
        .underline(
            logger
            .red("red and underlined").tab()
            .italic(logger.strike("italic and struck")).tab()
            .yellow("yellow and underlined")
        )
        .new_line(2)
        .bold("bold").space(1)
        .italic("italic").space(1)
        .dim("dim").space(1)
        .blink("blink").space(1)
        .reverse("reverse").space(1)
        .hidden("hidden").append(" <- hidden")
        .new_line(2)
        .to_cout();

    logger
        .red("red").space(1)
        .green("green").space(1)
        .blue("blue").space(1)
        .magenta("magenta").space(1)
        .cyan("cyan").space(1)
        .bright_yellow("bright yellow")
        .new_line()
        .bg_red("red background").space(1)
        .bg_green("green background").space(1)
        .bg_blue("blue background")
        .new_line(2)
        .to_cout();

    logger
        .log("Application started").new_line()
        .info("Configuration loaded").new_line()
        .success("Health check passed").new_line()
        .warning("This is a warning").new_line()
        .debug("Debug details enabled").new_line()
        .trace("Trace message").new_line()
        .error("An example error message")
        .new_line(2)
        .to_cout();

    logger
        .tag(
            "status",
            logger.bg_green( logger.black("online") ).to_string()
        )
        .space(3)
        .tag("version", "1.0.0")
        .new_line()
        .append("Indented text:")
        .tab(2)
        .append("two tabs")
        .to_cout();

    std::pair<std::string, int> pair = {"MyLogger", 420};
    MyLogger().pair(pair).new_line(2).to_cout();
}
