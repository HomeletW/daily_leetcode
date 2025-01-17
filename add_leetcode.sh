#!/bin/bash

# stop on first error & pipe fail
set -e
set -o pipefail

function usage() {
    echo "add_leetcode.sh [--help] [-n|--name]"
    echo "    Utilities to add an leetcode to the project."
    echo "    -h, --help"
    echo "        Print this message and exit."
    echo "    -n, --name"
    echo "        Provide the leetcode name directly."
}

QUESTION_NUMBER=
TEST_NAME=
URL=

# Arguments
while [[ $# -gt 0 ]]; do
  case $1 in
    -h|--help)
      usage
      exit 0
      ;;
    -n|--name)
      shift
      QUESTION_NUMBER=$(echo "$*" | awk -F'. ' '{print $1}')
      TEST_NAME=$(echo "$*" | awk -F'. ' '{sub($1". ", ""); print $0}')
      break
      ;;
    *)
      echo "Unknown option $1"
      usage
      exit 1
      ;;
  esac
done

if [ -z "$QUESTION_NUMBER" ]; then
  read -r -p "Question Number?   " QUESTION_NUMBER
fi

if [ -z "$TEST_NAME" ]; then
  read -r -p "Test Name?         " TEST_NAME
fi

if [ -f "q${QUESTION_NUMBER}.cpp" ]; then
    echo "The cpp answer for question ${QUESTION_NUMBER} already existed."
    exit
fi

P_TEST_NAME=$(echo "${TEST_NAME}" | tr ' ' '-' | awk '{print tolower($0)}')
URL="https://leetcode.com/problems/${P_TEST_NAME}"

while true; do
  read -r -p "Adding q${QUESTION_NUMBER} at ${URL}... Confirm? [Y]/n  " CONFIRMATION
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
TEMPLATE_CMAKE="add_executable(q${QUESTION_NUMBER} q${QUESTION_NUMBER}.cpp)"

echo "${TEMPLATE_CPP}" > "q${QUESTION_NUMBER}.cpp"
echo "${TEMPLATE_CMAKE}" >> CMakeLists.txt
git add CMakeLists.txt
git commit -m "Added q${QUESTION_NUMBER}.cpp"
git add "q${QUESTION_NUMBER}.cpp"
