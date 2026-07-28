import re
import subprocess

TARGET_DIR = "ex02"


def main():
    program_command = ["./ex02/ex02"]
    log_file_path = "19920104_091532.log"

    test_program_output(log_file_path, program_command)


##############################################################################
##############################################################################


def sanitize_line(line: str) -> str:
    return re.sub(r"^\[.*?\]\s*", "", line.strip())


def run_fclean():
    print(
        f"\n\033[1;33m--- Cleaning up with 'make fclean' inside '{TARGET_DIR}' --- \033[0m\n",
        flush=True,
    )
    subprocess.run(
        ["make", "fclean"],
        check=False,
        cwd=TARGET_DIR,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )


def test_program_output(expected_log_path: str, command: list[str]) -> bool:

    try:
        with open(expected_log_path, "r", encoding="utf-8") as f:
            expected_lines = [sanitize_line(line) for line in f if line.strip()]
    except FileNotFoundError:
        print(f"\033[1;31m>>> ❌ Log file '{expected_log_path}' not found. <<<\033[0m")
        return False

    print(
        f"\033[1;36m*** Building project with make inside '{TARGET_DIR}' ***\n\033[0m"
    )
    make_result = subprocess.run(
        ["make"],
        check=False,
        cwd=TARGET_DIR,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    if make_result.returncode != 0:
        print("\033[91m>>> ❌ 'make' failed. Aborting test. <<<\033[0m")
        return False
    print("\033[1;32m>>> ✅ Build successful! <<<\033[0m")

    with open(expected_log_path, "r", encoding="utf-8") as f:
        expected_lines = [sanitize_line(line) for line in f if line.strip()]

    try:
        result = subprocess.run(command, capture_output=True, text=True, check=True)
    except subprocess.CalledProcessError as e:
        print(
            f"\033[31m*** ❌ Execution failed with return code {e.returncode} ***\033[0m"
        )
        print(f"\033[1;31m>>> Error output:\n{e.stderr} <<<\033[0m")
        return False

    actual_lines = [
        sanitize_line(line) for line in result.stdout.splitlines() if line.strip()
    ]

    if len(expected_lines) != len(actual_lines):
        print(
            f"\033[1;31m\n *** ❌ Line count mismatch: Expected {len(expected_lines)} lines, got {len(actual_lines)} lines. ***\033[0m"
        )

    mismatches = 0
    max_lines = max(len(expected_lines), len(actual_lines))

    run_fclean()

    for index in range(max_lines):
        expected = expected_lines[index] if index < len(expected_lines) else "<EOF>"
        actual = actual_lines[index] if index < len(actual_lines) else "<EOF>"

        if expected != actual:
            mismatches += 1
            print(f"\033[31m❌ Mismatch at line {index + 1}:\033[0m")
            print(f"\033[36m   Expected: {expected}\033[0m")
            print(f"\033[31m   Actual:   {actual}\033[0m\n")

    if mismatches == 0 and len(expected_lines) == len(actual_lines):
        print("\033[1;32m*************************************************\033[0m")
        print("\033[1;32m ✅ Success! All log lines match expected output.\033[0m")
        print("\033[1;32m*************************************************\033[0m")
        return True
    else:
        print("\033[1;31m****************************************************\033[0m")
        print(f"\033[1;31m ❌ Test failed with {mismatches} line mismatch(es).\033[0m")
        print("\033[1;31m****************************************************\033[0m")
        return False


##############################################################################
##############################################################################

if __name__ == "__main__":
    main()
