#!/bin/bash

# stop on first error & pipe fail
set -e
set -o pipefail

function usage() {
    echo "Usage: $0 [--help] question_numbers..."
    echo "    Utilities to add one or more LeetCode solutions to the project."
    echo "    -h, --help"
    echo "        Print this message and exit."
}

# If no arguments are given, print usage and exit
if [ $# -eq 0 ]; then
    usage
    exit 1
fi

# Parse options
QUESTION_NUMBERS=()
while [[ $# -gt 0 ]]; do
  case $1 in
    -h|--help)
      usage
      exit 0
      ;;
    *)
      # Treat every non-option argument as a question number
      QUESTION_NUMBERS+=("$1")
      shift
      ;;
  esac
done

CURRENT_DATE=$(date +"%Y-%m-%d")

# For each question number, confirm, then commit
for QUESTION_NUMBER in "${QUESTION_NUMBERS[@]}"; do

    if [ ! -e "q${QUESTION_NUMBER}.cpp" ]; then
        echo "The cpp answer for question ${QUESTION_NUMBER} does not exist."
        continue
    fi

    while true; do
      read -r -p "Committing q${QUESTION_NUMBER} ... Confirm? [Y]/n  " CONFIRMATION
      CONFIRMATION=${CONFIRMATION:-Y}

      if [[ "$CONFIRMATION" =~ ^[Yy]$ ]]; then
          break
      elif [[ "$CONFIRMATION" =~ ^[Nn]$ ]]; then
          echo "Skipping q${QUESTION_NUMBER}"
          continue 2  # move on to the next QUESTION_NUMBER
      else
          echo "Invalid input. Please enter Y for yes or N for no."
      fi
    done

    TEMPLATE_GIT_COMMIT_MSG="daily leetcode ${CURRENT_DATE} (q${QUESTION_NUMBER})"
    git add "q${QUESTION_NUMBER}.cpp" CMakeLists.txt
    git commit -m "${TEMPLATE_GIT_COMMIT_MSG}"
done
