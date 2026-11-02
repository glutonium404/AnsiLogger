#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <utility>

struct AnsiSequencesOn {
    inline static constexpr std::string_view reset = "\033[0m";
    inline static constexpr std::string_view bold = "\033[1m";
    inline static constexpr std::string_view italic = "\033[3m";
    inline static constexpr std::string_view underline = "\033[4m";
    inline static constexpr std::string_view dim = "\033[2m";
    inline static constexpr std::string_view blink = "\033[5m";
    inline static constexpr std::string_view reverse = "\033[7m";
    inline static constexpr std::string_view hidden = "\033[8m";
    inline static constexpr std::string_view strike = "\033[9m";
    inline static constexpr std::string_view red = "\033[31m";
    inline static constexpr std::string_view cyan = "\033[36m";
    inline static constexpr std::string_view black = "\033[30m";
    inline static constexpr std::string_view green = "\033[32m";
    inline static constexpr std::string_view yellow = "\033[33m";
    inline static constexpr std::string_view blue = "\033[34m";
    inline static constexpr std::string_view magenta = "\033[35m";
    inline static constexpr std::string_view white = "\033[37m";
    inline static constexpr std::string_view grey = "\033[90m";
    inline static constexpr std::string_view bg_black = "\033[40m";
    inline static constexpr std::string_view bg_red = "\033[41m";
    inline static constexpr std::string_view bg_green = "\033[42m";
    inline static constexpr std::string_view bg_yellow = "\033[43m";
    inline static constexpr std::string_view bg_blue = "\033[44m";
    inline static constexpr std::string_view bg_magenta = "\033[45m";
    inline static constexpr std::string_view bg_cyan = "\033[46m";
    inline static constexpr std::string_view bg_white = "\033[47m";
    inline static constexpr std::string_view bg_grey = "\033[100m";
    inline static constexpr std::string_view bright_black = "\033[90m";
    inline static constexpr std::string_view bright_red = "\033[91m";
    inline static constexpr std::string_view bright_green = "\033[92m";
    inline static constexpr std::string_view bright_yellow = "\033[93m";
    inline static constexpr std::string_view bright_blue = "\033[94m";
    inline static constexpr std::string_view bright_magenta = "\033[95m";
    inline static constexpr std::string_view bright_cyan = "\033[96m";
    inline static constexpr std::string_view bright_white = "\033[97m";
    inline static constexpr std::string_view heading = "\033[1;36m";
};
struct AnsiSequencesOff {
    inline static constexpr std::string_view heading = "\033[22;39m";
    inline static constexpr std::string_view bright_white = "\033[39m";
    inline static constexpr std::string_view bright_cyan = "\033[39m";
    inline static constexpr std::string_view bright_magenta = "\033[39m";
    inline static constexpr std::string_view bright_blue = "\033[39m";
    inline static constexpr std::string_view bright_yellow = "\033[39m";
    inline static constexpr std::string_view bright_green = "\033[39m";
    inline static constexpr std::string_view bright_red = "\033[39m";
    inline static constexpr std::string_view bright_black = "\033[39m";
    inline static constexpr std::string_view bg_grey = "\033[49m";
    inline static constexpr std::string_view bg_white = "\033[49m";
    inline static constexpr std::string_view bg_cyan = "\033[49m";
    inline static constexpr std::string_view bg_magenta = "\033[49m";
    inline static constexpr std::string_view bg_blue = "\033[49m";
    inline static constexpr std::string_view bg_yellow = "\033[49m";
    inline static constexpr std::string_view bg_green = "\033[49m";
    inline static constexpr std::string_view bg_red = "\033[49m";
    inline static constexpr std::string_view bg_black = "\033[49m";
    inline static constexpr std::string_view grey = "\033[39m";
    inline static constexpr std::string_view white = "\033[39m";
    inline static constexpr std::string_view magenta = "\033[39m";
    inline static constexpr std::string_view blue = "\033[39m";
    inline static constexpr std::string_view yellow = "\033[39m";
    inline static constexpr std::string_view green = "\033[39m";
    inline static constexpr std::string_view black = "\033[39m";
    inline static constexpr std::string_view cyan = "\033[39m";
    inline static constexpr std::string_view red = "\033[39m";
    inline static constexpr std::string_view strike = "\033[29m";
    inline static constexpr std::string_view hidden = "\033[28m";
    inline static constexpr std::string_view reverse = "\033[27m";
    inline static constexpr std::string_view blink = "\033[25m";
    inline static constexpr std::string_view dim = "\033[22m";
    inline static constexpr std::string_view underline = "\033[24m";
    inline static constexpr std::string_view italic = "\033[23m";
    inline static constexpr std::string_view bold = "\033[22m";
    inline static constexpr std::string_view reset = "\033[0m";
};

class AnsiLogger {
public:
    inline static bool has_nerd_font = true;

private:
    std::string _msg;

private:
    std::string build_msg(std::string_view opening_sequence, std::string_view msg, std::string_view closing_sequence = "") const {
        std::string result;
        result.reserve(
            _msg.size() + opening_sequence.size() + msg.size() + closing_sequence.size()
        );
        result.append(_msg);
        result.append(opening_sequence);
        result.append(msg);
        result.append(closing_sequence);

        return result;
    }

public:
    AnsiLogger() = default;

    AnsiLogger(std::string msg)
        : _msg(std::move(msg)) {}


    /////////////////////////////////////////////////////////////////
    ////////////////////--> TEXT STYLING <--/////////////////////////
    /////////////////////////////////////////////////////////////////

    //==================================================================
    AnsiLogger bold(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bold, msg, AnsiSequencesOff::bold));
    }

    AnsiLogger bold(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bold, ansi_logger._msg, AnsiSequencesOff::bold));
    }

    //==================================================================
    AnsiLogger italic(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::italic, msg, AnsiSequencesOff::italic));
    }

    AnsiLogger italic(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::italic, ansi_logger._msg, AnsiSequencesOff::italic));
    }

    //==================================================================
    AnsiLogger underline(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::underline, msg, AnsiSequencesOff::underline));
    }

    AnsiLogger underline(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::underline, ansi_logger._msg, AnsiSequencesOff::underline));
    }

    //==================================================================
    AnsiLogger dim(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::dim, msg, AnsiSequencesOff::dim));
    }

    AnsiLogger dim(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::dim, ansi_logger._msg, AnsiSequencesOff::dim));
    }

    //==================================================================
    AnsiLogger blink(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::blink, msg, AnsiSequencesOff::blink));
    }

    AnsiLogger blink(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::blink, ansi_logger._msg, AnsiSequencesOff::blink));
    }

    //==================================================================
    AnsiLogger reverse(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::reverse, msg, AnsiSequencesOff::reverse));
    }

    AnsiLogger reverse(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::reverse, ansi_logger._msg, AnsiSequencesOff::reverse));
    }

    //==================================================================
    AnsiLogger hidden(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::hidden, msg, AnsiSequencesOff::hidden));
    }

    AnsiLogger hidden(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::hidden, ansi_logger._msg, AnsiSequencesOff::hidden));
    }

    //==================================================================
    AnsiLogger strike(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::strike, msg, AnsiSequencesOff::strike));
    }

    AnsiLogger strike(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::strike, ansi_logger._msg, AnsiSequencesOff::strike));
    }

    /////////////////////////////////////////////////////////////////
    ///////////////--> FOREGROUND COLORS <--/////////////////////////
    /////////////////////////////////////////////////////////////////

    AnsiLogger red(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::red, msg, AnsiSequencesOff::red));
    }

    AnsiLogger cyan(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::cyan, msg, AnsiSequencesOff::cyan));
    }

    AnsiLogger black(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::black, msg, AnsiSequencesOff::black));
    }

    AnsiLogger green(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::green, msg, AnsiSequencesOff::green));
    }

    AnsiLogger yellow(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::yellow, msg, AnsiSequencesOff::yellow));
    }

    AnsiLogger blue(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::blue, msg, AnsiSequencesOff::blue));
    }

    AnsiLogger magenta(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::magenta, msg, AnsiSequencesOff::magenta));
    }

    AnsiLogger white(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::white, msg, AnsiSequencesOff::white));
    }

    AnsiLogger grey(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::grey, msg, AnsiSequencesOff::grey));
    }

    AnsiLogger bright_black(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bright_black, msg, AnsiSequencesOff::bright_black));
    }

    AnsiLogger bright_red(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bright_red, msg, AnsiSequencesOff::bright_red));
    }

    AnsiLogger bright_green(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bright_green, msg, AnsiSequencesOff::bright_green));
    }

    AnsiLogger bright_yellow(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bright_yellow, msg, AnsiSequencesOff::bright_yellow));
    }

    AnsiLogger bright_blue(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bright_blue, msg, AnsiSequencesOff::bright_blue));
    }

    AnsiLogger bright_magenta(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bright_magenta, msg, AnsiSequencesOff::bright_magenta));
    }

    AnsiLogger bright_cyan(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bright_cyan, msg, AnsiSequencesOff::bright_cyan));
    }

    AnsiLogger bright_white(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bright_white, msg, AnsiSequencesOff::bright_white));
    }

    /////////////////////////////////////////////////////////////////
    ///////////////--> BACKGROUND COLORS <--/////////////////////////
    /////////////////////////////////////////////////////////////////

    //==================================================================
    AnsiLogger bg_black(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_black, msg, AnsiSequencesOff::bg_black));
    }

    AnsiLogger bg_black(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_black, ansi_logger._msg, AnsiSequencesOff::bg_black));
    }

    //==================================================================
    AnsiLogger bg_red(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_red, msg, AnsiSequencesOff::bg_red));
    }

    AnsiLogger bg_red(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_red, ansi_logger._msg, AnsiSequencesOff::bg_red));
    }

    //==================================================================
    AnsiLogger bg_green(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_green, msg, AnsiSequencesOff::bg_green));
    }

    AnsiLogger bg_green(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_green, ansi_logger._msg, AnsiSequencesOff::bg_green));
    }

    //==================================================================
    AnsiLogger bg_yellow(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_yellow, msg, AnsiSequencesOff::bg_yellow));
    }

    AnsiLogger bg_yellow(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_yellow, ansi_logger._msg, AnsiSequencesOff::bg_yellow));
    }

    //==================================================================
    AnsiLogger bg_blue(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_blue, msg, AnsiSequencesOff::bg_blue));
    }

    AnsiLogger bg_blue(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_blue, ansi_logger._msg, AnsiSequencesOff::bg_blue));
    }

    //==================================================================
    AnsiLogger bg_magenta(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_magenta, msg, AnsiSequencesOff::bg_magenta));
    }

    AnsiLogger bg_magenta(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_magenta, ansi_logger._msg, AnsiSequencesOff::bg_magenta));
    }

    //==================================================================
    AnsiLogger bg_cyan(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_cyan, msg, AnsiSequencesOff::bg_cyan));
    }

    AnsiLogger bg_cyan(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_cyan, ansi_logger._msg, AnsiSequencesOff::bg_cyan));
    }

    //==================================================================
    AnsiLogger bg_white(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_white, msg, AnsiSequencesOff::bg_white));
    }

    AnsiLogger bg_white(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_white, ansi_logger._msg, AnsiSequencesOff::bg_white));
    }

    //==================================================================
    AnsiLogger bg_grey(std::string_view msg) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_grey, msg, AnsiSequencesOff::bg_grey));
    }

    AnsiLogger bg_grey(const AnsiLogger& ansi_logger) const {
        return AnsiLogger(build_msg(AnsiSequencesOn::bg_grey, ansi_logger._msg, AnsiSequencesOff::bg_grey));
    }


    /////////////////////////////////////////////////////////////////
    ///////////////////--> UTILITY <--///////////////////////////////
    /////////////////////////////////////////////////////////////////

    AnsiLogger log(std::string_view msg) const {
        std::string on_seq  = std::string(AnsiSequencesOn::bg_cyan) + std::string(AnsiSequencesOn::black);
        std::string off_seq = std::string(AnsiSequencesOff::black) + std::string(AnsiSequencesOff::bg_cyan);
        std::string icon = has_nerd_font ? " LOG: " : "[LOG]: ";

        return AnsiLogger(build_msg(on_seq, icon + std::string(msg), off_seq));
    }

    AnsiLogger warning(std::string_view msg) const {
        std::string on_seq  = std::string(AnsiSequencesOn::bg_yellow) + std::string(AnsiSequencesOn::black);
        std::string off_seq = std::string(AnsiSequencesOff::black) + std::string(AnsiSequencesOff::bg_yellow);
        std::string icon = has_nerd_font ? " WRN: " : "[WRN]: ";
        return AnsiLogger(build_msg(on_seq, icon + std::string(msg), off_seq));
    }

    AnsiLogger error(std::string_view msg) const {
        std::string on_seq  = std::string(AnsiSequencesOn::bg_red) + std::string(AnsiSequencesOn::black);
        std::string off_seq = std::string(AnsiSequencesOff::black) + std::string(AnsiSequencesOff::bg_red);
        std::string icon = has_nerd_font ? " ERR: " : "[ERR]: ";
        return AnsiLogger(build_msg(on_seq, icon + std::string(msg), off_seq));
    }

    AnsiLogger success(std::string_view msg) const {
        std::string on_seq = std::string(AnsiSequencesOn::bg_green) + std::string(AnsiSequencesOn::black);
        std::string off_seq = std::string(AnsiSequencesOff::black) + std::string(AnsiSequencesOff::bg_green);
        std::string icon = has_nerd_font ? " OK : " : "[SUC]: ";
        return AnsiLogger(build_msg(on_seq, icon + std::string(msg), off_seq));
    }

    AnsiLogger debug(std::string_view msg) const {
        std::string on_seq = std::string(AnsiSequencesOn::bg_magenta) + std::string(AnsiSequencesOn::black);
        std::string off_seq = std::string(AnsiSequencesOff::black) + std::string(AnsiSequencesOff::bg_magenta);
        std::string icon = has_nerd_font ? " DBG: " : "[DBG]: ";
        return AnsiLogger(build_msg(on_seq, icon  + std::string(msg), off_seq));
    }

    AnsiLogger info(std::string_view msg) const {
        std::string on_seq = std::string(AnsiSequencesOn::bg_blue) + std::string(AnsiSequencesOn::white);
        std::string off_seq = std::string(AnsiSequencesOff::white) + std::string(AnsiSequencesOff::bg_blue);
        std::string icon = has_nerd_font ? " INF: " : "[INF]: ";
        return AnsiLogger(build_msg(on_seq, icon + std::string(msg), off_seq));
    }

    AnsiLogger trace(std::string_view msg) const {
        std::string on_seq = std::string(AnsiSequencesOn::bg_grey) + std::string(AnsiSequencesOn::black);
        std::string off_seq = std::string(AnsiSequencesOff::black) + std::string(AnsiSequencesOff::bg_grey);
        std::string icon = has_nerd_font ? " TRC: " : "[TRC]: ";
        return AnsiLogger(build_msg(on_seq, icon + std::string(msg), off_seq));
    }

    // Formats a key-value pair, highlighting the key in bright blue and value in white
    AnsiLogger tag(std::string_view key, std::string_view value) const {
        std::string formatted = std::string(AnsiSequencesOn::bright_blue) + "[" + std::string(key) + "] " +
            std::string(AnsiSequencesOff::bright_blue) + std::string(value);
        return AnsiLogger(_msg + formatted);
    }

    // Appends a plain text message to the chain without resetting or changing colors
    AnsiLogger append(std::string_view msg) const {
        return AnsiLogger(_msg + std::string(msg));
    }


    AnsiLogger push_back(const char c) {
        _msg.push_back(c);
        return *this;
    }

    AnsiLogger new_line(size_t n = 1) {
        _msg.resize(_msg.size()+n, '\n');
        return *this;
    }

    AnsiLogger tab(size_t n = 1) {
        _msg.resize(_msg.size()+n, '\t');
        return *this;
    }

    AnsiLogger space(size_t n = 1) {
        _msg.resize(_msg.size()+n, ' ');
        return *this;
    }

    AnsiLogger reset() const {
        return AnsiLogger(_msg + std::string(AnsiSequencesOn::reset));
    }

    std::string to_string() const {
        return _msg + std::string(AnsiSequencesOn::reset);
    }

    void to_cout(const bool new_line = true) {
        std::cout << to_string();
        if(new_line)
            std::cout << "\n";
    }
};
