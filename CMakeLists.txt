cmake_minimum_required(VERSION 3.26)
project(Leetcode)

set(CMAKE_CXX_STANDARD 20)

add_executable(util_test util_test.cpp)

SET(CMAKE_C_COMPILER clang)
SET(CMAKE_C_FLAGS "-Wall -std=c99")
SET(CMAKE_C_FLAGS_DEBUG "-g")
SET(CMAKE_C_FLAGS_MINSIZEREL "-Os -DNDEBUG")
SET(CMAKE_C_FLAGS_RELEASE "-O4 -DNDEBUG")
SET(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

SET(CMAKE_CXX_COMPILER clang++)
SET(CMAKE_CXX_FLAGS "-Wall -fsanitize=address -fsanitize=undefined")
SET(CMAKE_CXX_FLAGS_DEBUG "-g")
SET(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
SET(CMAKE_CXX_FLAGS_RELEASE "-O4 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(q74 1_99/q74.cpp)
add_executable(q95 1_99/q95.cpp)
add_executable(q2616 1000/q2616.cpp)
add_executable(q797 700_799/q797.cpp)
add_executable(q81 1_99/q81.cpp)
add_executable(q518 500_599/q518.cpp)
add_executable(q1615 1000/q1615.cpp)
add_executable(q1203 1000/q1203.cpp)
add_executable(q459 400_499/q459.cpp)
add_executable(q168 100_199/q168.cpp)
add_executable(q767 700_799/q767.cpp)
add_executable(q68 1_99/q68.cpp)
add_executable(q97 1_99/q97.cpp)
add_executable(q646 600_699/q646.cpp)
add_executable(q403 400_499/q403.cpp)
add_executable(q165 100_199/q165.cpp)
add_executable(q881 800_899/q881.cpp)
add_executable(q237 200_299/q237.cpp)
add_executable(q89 1_99/q89.cpp)
add_executable(q88 1_99/q88.cpp)
add_executable(q28 1_99/q28.cpp)
add_executable(q100 100_199/q100.cpp)
add_executable(q42 1_99/q42.cpp)
add_executable(q14 1_99/q14.cpp)
add_executable(q15 1_99/q15.cpp)
add_executable(q383 300_399/q383.cpp)
add_executable(q1 1_99/q1.cpp)
add_executable(q274 200_299/q274.cpp)
add_executable(q20 1_99/q20.cpp)
add_executable(q36 1_99/q36.cpp)
add_executable(q71 1_99/q71.cpp)
add_executable(q80 1_99/q80.cpp)
add_executable(q55 1_99/q55.cpp)
add_executable(q189 100_199/q189.cpp)
add_executable(q169 100_199/q169.cpp)
add_executable(q2 1_99/q2.cpp)
add_executable(q19 1_99/q19.cpp)
add_executable(q3 1_99/q3.cpp)
add_executable(q121 100_199/q121.cpp)
add_executable(q122 100_199/q122.cpp)
add_executable(q33 1_99/q33.cpp)
add_executable(q228 200_299/q228.cpp)
add_executable(q9 1_99/q9.cpp)
add_executable(q23 1_99/q23.cpp)
add_executable(q104 100_199/q104.cpp)
add_executable(q70 1_99/q70.cpp)
add_executable(q21 1_99/q21.cpp)
add_executable(q125 100_199/q125.cpp)
add_executable(q67 1_99/q67.cpp)
add_executable(q17 1_99/q17.cpp)
add_executable(q162 100_199/q162.cpp)
add_executable(q6 1_99/q6.cpp)
add_executable(q207 200_299/q207.cpp)
add_executable(q530 500_599/q530.cpp)
add_executable(q300 300_399/q300.cpp)
add_executable(q199 100_199/q199.cpp)
add_executable(q141 100_199/q141.cpp)
add_executable(q45 1_99/q45.cpp)
add_executable(q226 200_299/q226.cpp)
add_executable(q58 1_99/q58.cpp)
add_executable(q918 900_999/q918.cpp)
add_executable(q210 200_299/q210.cpp)
add_executable(q66 1_99/q66.cpp)
add_executable(q173 100_199/q173.cpp)
add_executable(q150 100_199/q150.cpp)
add_executable(q205 200_299/q205.cpp)
add_executable(q114 100_199/q114.cpp)
add_executable(q502 500_599/q502.cpp)
add_executable(q167 100_199/q167.cpp)
add_executable(q155 100_199/q155.cpp)
add_executable(q148 100_199/q148.cpp)
add_executable(q242 200_299/q242.cpp)
add_executable(q153 100_199/q153.cpp)
add_executable(q72 1_99/q72.cpp)
add_executable(q63 1_99/q63.cpp)
add_executable(q13 1_99/q13.cpp)
add_executable(q12 1_99/q12.cpp)
add_executable(q380 300_399/q380.cpp)
add_executable(q238 200_299/q238.cpp)
add_executable(q76 1_99/q76.cpp)
add_executable(q133 100_199/q133.cpp)
add_executable(q134 100_199/q134.cpp)
add_executable(q92 1_99/q92.cpp)
add_executable(q215 200_299/q215.cpp)
add_executable(q135 100_199/q135.cpp)
add_executable(q101 100_199/q101.cpp)
add_executable(q373 300_399/q373.cpp)
add_executable(q392 q392.cpp)
add_executable(q69 q69.cpp)
add_executable(q138 q138.cpp)
add_executable(q11 q11.cpp)
add_executable(q427 q427.cpp)
add_executable(q221 q221.cpp)
add_executable(q452 q452.cpp)
add_executable(q56 q56.cpp)
add_executable(q295 q295.cpp)
add_executable(q25 q25.cpp)
add_executable(q222 q222.cpp)
add_executable(q120 q120.cpp)
add_executable(q123 q123.cpp)
add_executable(q64 q64.cpp)
add_executable(q289 q289.cpp)
add_executable(q151 q151.cpp)
add_executable(q230 q230.cpp)
add_executable(q105 q105.cpp)
add_executable(q52 q52.cpp)
add_executable(q106 q106.cpp)
add_executable(q98 q98.cpp)
add_executable(q103 q103.cpp)
add_executable(q139 q139.cpp)
add_executable(q86 q86.cpp)
