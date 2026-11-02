#include "AnsiLogger.hpp"

int main() {

    AnsiLogger::has_nerd_font = true;

    AnsiLogger logger;
    logger
        .italic(
            logger
            .bg_magenta(logger.blue("my"))
            .space(4)
            .yellow("name ")
            .red("is ")
            .green("meow ")
            .cyan("meow")
        )
        .new_line()
        .append("hi")
        .new_line()
        .dim(
            logger
            .bg_magenta(logger.blue("my"))
            .space(4)
            .yellow("name ")
            .red("is ")
            .green("meow ")
            .cyan("meow")
        )
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
