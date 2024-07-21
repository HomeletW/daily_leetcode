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

QUESTION_NUMBER=$1
shift

if [ ! -f "q${QUESTION_NUMBER}.cpp" ]; then
    echo "The cpp answer for question ${QUESTION_NUMBER} does not exist."
    exit
fi

while true; do
  read -r -p "Committing q${QUESTION_NUMBER} ... Confirm? [Y]/n" CONFIRMATION
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

TEMPLATE_CPP="/**
 * ${QUESTION_NUMBER}. ${TEST_NAME}
 * ${URL}
 *
 * Date: ${CURRENT_DATE}
 */

#include \"my_util.hpp\"

using namespace std;

int main() {

}"
TEMPLATE_CMAKE="add_leetcode(q${QUESTION_NUMBER})"
TEMPLATE_GIT_COMMIT_MSG="${CURRENT_DATE}: Daily Leetcode ${QUESTION_NUMBER}."

echo "${TEMPLATE_CPP}" > "q${QUESTION_NUMBER}.cpp"
echo "${TEMPLATE_CMAKE}" >> CMakeLists.txt
git add "q${QUESTION_NUMBER}.cpp" CMakeLists.txt
git commit -m "${TEMPLATE_GIT_COMMIT_MSG}"
