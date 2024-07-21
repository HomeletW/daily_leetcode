#!/bin/bash

# stop on first error & pipe fail
set -e
set -o pipefail

function usage() {
    echo "commit_leetcode.sh [--help] question_number"
    echo "    Utilities to add an leetcode to the project."
    echo "    -h, --help"
    echo "        Print this message and exit."
}

QUESTION_NUMBER=

QUESTION_NUMBER=$1
shift

# Arguments
while [[ $# -gt 0 ]]; do
  case $1 in
    -h|--help)
      usage
      exit 0
      ;;
    *)
      echo "Unknown option $1"
      usage
      exit 1
      ;;
  esac
done

if [ ! -e "q${QUESTION_NUMBER}.cpp" ]; then
    echo "The cpp answer for question ${QUESTION_NUMBER} does not exist."
    exit
fi

while true; do
  read -r -p "Committing q${QUESTION_NUMBER} ... Confirm? [Y]/n  " CONFIRMATION
  CONFIRMATION=${CONFIRMATION:-Y}

  if [[ "$CONFIRMATION" =~ ^[Yy]$ ]]; then
      break
  elif [[ "$CONFIRMATION" =~ ^[Nn]$ ]]; then
      echo "Exiting"
      exit
  else
      echo "Invalid input. Please enter Y for yes or N for no."
  fi
done

CURRENT_DATE=$(date +"%Y-%m-%d")

TEMPLATE_GIT_COMMIT_MSG="daily leetcode ${CURRENT_DATE}"

git add "q${QUESTION_NUMBER}.cpp" CMakeLists.txt
git commit -m "${TEMPLATE_GIT_COMMIT_MSG}"
