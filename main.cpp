#include "AnsiLogger.hpp"

int main() {

    AnsiLogger logger;

    // logger
    //     .underline("this")
    //     .red("that")
    //     .to_cout();

    logger.bg_blue(
        logger.blink(
            logger
            .yellow("the bg should be black ")
        )
    )
    .italic(
        logger.green("meow meow").bright_red("haha")
    ).to_cout();

    logger.italic(
        logger.underline(
            logger.cyan("hellow").yellow("ywllo")
        )
    ).to_cout();

    // // Text formatting
    // logger.bold("Bold text").to_cout();
    // logger.italic("Italic text").to_cout();
    // logger.underline("Underlined text").to_cout();
    // logger.dim("Dimmed text").to_cout();
    // logger.blink("Blinking text").to_cout();
    // logger.reverse("Reversed text").to_cout();
    // logger.hidden("Hidden text").to_cout();
    // logger.strike("Strikethrough text").to_cout();
    //
    // std::cout << '\n';
    //
    // // Foreground colors
    // logger.black("Black text").to_cout();
    // logger.red("Red text").to_cout();
    // logger.green("Green text").to_cout();
    // logger.yellow("Yellow text").to_cout();
    // logger.blue("Blue text").to_cout();
    // logger.magenta("Magenta text").to_cout();
    // logger.cyan("Cyan text").to_cout();
    // logger.white("White text").to_cout();
    // logger.gray("Gray text").to_cout();
    // logger.grey("Grey text").to_cout();
    //
    // std::cout << '\n';
    //
    // // Background colors
    // logger.bg_black("Black background").to_cout();
    // logger.bg_red("Red background").to_cout();
    // logger.bg_green("Green background").to_cout();
    // logger.bg_yellow("Yellow background").to_cout();
    // logger.bg_blue("Blue background").to_cout();
    // logger.bg_magenta("Magenta background").to_cout();
    // logger.bg_cyan("Cyan background").to_cout();
    // logger.bg_white("White background").to_cout();
    // logger.bg_gray("Gray background").to_cout();
    // logger.bg_grey("Grey background").to_cout();
    //
    // std::cout << '\n';
    //
    // // Bright colors
    // logger.bright_black("Bright black").to_cout();
    // logger.bright_red("Bright red").to_cout();
    // logger.bright_green("Bright green").to_cout();
    // logger.bright_yellow("Bright yellow").to_cout();
    // logger.bright_blue("Bright blue").to_cout();
    // logger.bright_magenta("Bright magenta").to_cout();
    // logger.bright_cyan("Bright cyan").to_cout();
    // logger.bright_white("Bright white").to_cout();
    //
    // std::cout << '\n';
    //
    // // Custom heading
    // logger.heading("ANSI LOGGER DEMONSTRATION").to_cout();
    //
    // std::cout << '\n';
    //
    // // Logging levels
    // logger.log("Application started successfully").to_cout();
    // logger.warning("Configuration file not found").to_cout();
    // logger.error("Failed to establish database connection").to_cout();
    //
    // std::cout << '\n';
    //
    // // Chaining
    // logger.bold("This is bold and red").red("This is red").to_cout();

    // logger
    //     .heading("ANSI LOGGER DEMONSTRATION")
    //     .new_line()
    //     .new_line()
    //     .bold("Text Formatting")
    //     .italic("Italic")
    //     .underline("Underline")
    //     .dim("Dim")
    //     .blink("Blink")
    //     .reverse("Reverse")
    //     .hidden("Hidden")
    //     .strike("Strikethrough")
    //     .bold("Foreground Colors")
    //     .black("Black")
    //     .red("Red")
    //     .green("Green")
    //     .yellow("Yellow")
    //     .blue("Blue")
    //     .magenta("Magenta")
    //     .cyan("Cyan")
    //     .white("White")
    //     .gray("Gray")
    //     .grey("Grey")
    //     .bold("Background Colors")
    //     .bg_black("Black background")
    //     .bg_red("Red background")
    //     .bg_green("Green background")
    //     .bg_yellow("Yellow background")
    //     .bg_blue("Blue background")
    //     .bg_magenta("Magenta background")
    //     .bg_cyan("Cyan background")
    //     .bg_white("White background")
    //     .bg_gray("Gray background")
    //     .bg_grey("Grey background")
    //     .bold("Bright Colors")
    //     .bright_black("Bright Black")
    //     .bright_red("Bright Red")
    //     .bright_green("Bright Green")
    //     .bright_yellow("Bright Yellow")
    //     .bright_blue("Bright Blue")
    //     .bright_magenta("Bright Magenta")
    //     .bright_cyan("Bright Cyan")
    //     .bright_white("Bright White")
    //     .bold("Logging Levels")
    //     .log("Application started successfully")
    //     .warning("Configuration file not found")
    //     .error("Failed to establish database connection")
    //     .to_cout();

    // std::cout << AnsiiSequences::blink << AnsiiSequences::cyan << "i am blinking" << AnsiiSequences::reset << std::endl;
    return 0;
}
