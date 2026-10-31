#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <utility>

struct AnsiSequences {
    inline static constexpr std::string_view reset          = "\033[0m";
    inline static constexpr std::string_view bold           = "\033[1m";
    inline static constexpr std::string_view italic         = "\033[3m";
    inline static constexpr std::string_view underline      = "\033[4m";
    inline static constexpr std::string_view dim            = "\033[2m";
    inline static constexpr std::string_view blink          = "\033[5m";
    inline static constexpr std::string_view reverse        = "\033[7m";
    inline static constexpr std::string_view hidden         = "\033[8m";
    inline static constexpr std::string_view strike         = "\033[9m";
    inline static constexpr std::string_view red            = "\033[31m";
    inline static constexpr std::string_view cyan           = "\033[36m";
    inline static constexpr std::string_view black          = "\033[30m";
    inline static constexpr std::string_view green          = "\033[32m";
    inline static constexpr std::string_view yellow         = "\033[33m";
    inline static constexpr std::string_view blue           = "\033[34m";
    inline static constexpr std::string_view magenta        = "\033[35m";
    inline static constexpr std::string_view white          = "\033[37m";
    inline static constexpr std::string_view grey           = "\033[90m";
    inline static constexpr std::string_view bg_black       = "\033[40m";
    inline static constexpr std::string_view bg_red         = "\033[41m";
    inline static constexpr std::string_view bg_green       = "\033[42m";
    inline static constexpr std::string_view bg_yellow      = "\033[43m";
    inline static constexpr std::string_view bg_blue        = "\033[44m";
    inline static constexpr std::string_view bg_magenta     = "\033[45m";
    inline static constexpr std::string_view bg_cyan        = "\033[46m";
    inline static constexpr std::string_view bg_white       = "\033[47m";
    inline static constexpr std::string_view bg_grey        = "\033[100m";
    inline static constexpr std::string_view bright_black   = "\033[90m";
    inline static constexpr std::string_view bright_red     = "\033[91m";
    inline static constexpr std::string_view bright_green   = "\033[92m";
    inline static constexpr std::string_view bright_yellow  = "\033[93m";
    inline static constexpr std::string_view bright_blue    = "\033[94m";
    inline static constexpr std::string_view bright_magenta = "\033[95m";
    inline static constexpr std::string_view bright_cyan    = "\033[96m";
    inline static constexpr std::string_view bright_white   = "\033[97m";
    inline static constexpr std::string_view heading        = "\033[1;36m";
};

class AnsiLogger {
private:
    std::string _msg;

private:
    std::string build_msg(std::string_view sequence, std::string_view msg) const {
        std::string result;
        result.reserve(
            _msg.size() + sequence.size() + msg.size()
        );
        result.append(_msg);
        result.append(sequence);
        result.append(msg);

        return result;
    }

    std::string build_msg(std::string_view sequence, std::string_view prefix, std::string_view msg) const {
        std::string result;
        result.reserve(
            _msg.size() + sequence.size() + prefix.size() + msg.size()
        );
        result.append(_msg);
        result.append(sequence);
        result.append(prefix);
        result.append(msg);

        return result;
    }

public:
    AnsiLogger() = default;
    explicit AnsiLogger(std::string msg): _msg(std::move(msg)) {}

    /////////////////////////////////////////////////////////////////
    ////////////////////--> TEXT STYLING <--/////////////////////////
    /////////////////////////////////////////////////////////////////

    //==================================================================
    AnsiLogger bold(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bold, msg));
    }

    AnsiLogger bold(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::bold, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger italic(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::italic, msg));
    }

    AnsiLogger italic(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::italic, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger underline(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::underline, msg));
    }

    AnsiLogger underline(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::underline, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger dim(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::dim, msg));
    }

    AnsiLogger dim(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::dim, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger blink(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::blink, msg));
    }

    AnsiLogger blink(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::blink, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger reverse(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::reverse, msg));
    }

    AnsiLogger reverse(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::reverse, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger hidden(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::hidden, msg));
    }

    AnsiLogger hidden(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::hidden, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger strike(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::strike, msg));
    }

    AnsiLogger strike(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::strike, ansi_logger._msg));
    }

    /////////////////////////////////////////////////////////////////
    ///////////////--> FOREGROUND COLORS <--/////////////////////////
    /////////////////////////////////////////////////////////////////

    AnsiLogger red(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::red, msg));
    }

    AnsiLogger cyan(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::cyan, msg));
    }

    AnsiLogger black(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::black, msg));
    }

    AnsiLogger green(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::green, msg));
    }

    AnsiLogger yellow(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::yellow, msg));
    }

    AnsiLogger blue(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::blue, msg));
    }

    AnsiLogger magenta(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::magenta, msg));
    }

    AnsiLogger white(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::white, msg));
    }

    AnsiLogger grey(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::grey, msg));
    }

    AnsiLogger bright_black(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bright_black, msg));
    }

    AnsiLogger bright_red(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bright_red, msg));
    }

    AnsiLogger bright_green(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bright_green, msg));
    }

    AnsiLogger bright_yellow(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bright_yellow, msg));
    }

    AnsiLogger bright_blue(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bright_blue, msg));
    }

    AnsiLogger bright_magenta(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bright_magenta, msg));
    }

    AnsiLogger bright_cyan(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bright_cyan, msg));
    }

    AnsiLogger bright_white(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bright_white, msg));
    }

    /////////////////////////////////////////////////////////////////
    ///////////////--> BACKGROUND COLORS <--/////////////////////////
    /////////////////////////////////////////////////////////////////

    //==================================================================
    AnsiLogger bg_black(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_black, msg));
    }

    AnsiLogger bg_black(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_black, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger bg_red(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_red, msg));
    }

    AnsiLogger bg_red(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_red, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger bg_green(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_green, msg));
    }

    AnsiLogger bg_green(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_green, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger bg_yellow(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_yellow, msg));
    }

    AnsiLogger bg_yellow(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_yellow, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger bg_blue(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_blue, msg));
    }

    AnsiLogger bg_blue(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_blue, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger bg_magenta(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_magenta, msg));
    }

    AnsiLogger bg_magenta(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_magenta, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger bg_cyan(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_cyan, msg));
    }

    AnsiLogger bg_cyan(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_cyan, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger bg_white(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_white, msg));
    }

    AnsiLogger bg_white(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_white, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger bg_grey(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_grey, msg));
    }

    AnsiLogger bg_grey(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::bg_grey, ansi_logger._msg));
    }

    //==================================================================
    AnsiLogger heading(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::heading, msg));
    }

    AnsiLogger heading(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequences::heading, ansi_logger._msg));
    }


    /////////////////////////////////////////////////////////////////
    ///////////////////--> UTILITY <--///////////////////////////////
    /////////////////////////////////////////////////////////////////

    AnsiLogger log(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::cyan, "󰋼 LOG: ", msg));
    }

    AnsiLogger warning(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::yellow, " WRN: ", msg));
    }

    AnsiLogger error(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequences::red, " ERR: ", msg));
    }

    AnsiLogger new_line() const {
        return AnsiLogger(_msg + "\n");
    }

    AnsiLogger reset() const {
        return AnsiLogger(_msg + std::string(AnsiSequences::reset));
    }

    std::string to_string() {
        if(!_msg.empty() && _msg.back() == ' ')
            return _msg.substr(0, _msg.size()-1) + std::string(AnsiSequences::reset);
        return _msg + std::string(AnsiSequences::reset);
    }

    void to_cout(const bool new_line = true) {
        std::cout << to_string();
        if(new_line)
            std::cout << "\n";
    }
};
