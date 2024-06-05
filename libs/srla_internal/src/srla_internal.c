#include "srla_internal.h"

/* 配列の要素数を取得 */
#define SRLA_NUM_ARRAY_ELEMENTS(array) ((sizeof(array)) / (sizeof(array[0])))
/* プリセットの要素定義 */
#define SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(array) array, SRLA_NUM_ARRAY_ELEMENTS(array)

/* 係数頻度テーブル */
const uint32_t g_parameter_frequency_table[256] = {
    76095348,72254718,72258289,63169964,63262546,52582715,52810486,42799643,43131372,34676884,35025512,28243398,28590416,23273860,23593636,19444616,19733938,16446878,16704846,14066952,14313948,12156323,12394627,10604076,10825956,9314730,9540212,8242626,8464666,7332022,7557602,6570127,6797925,5912557,6142141,5354150,5585914,4869738,5094289,4442801,4677350,4061066,4300506,3734416,3970760,3443153,3677752,3189336,3415782,2954645,3178799,2752660,2967304,2569629,2777818,2404070,2602129,2251526,2443398,2115191,2295804,1994923,2161063,1881480,2038816,1782001,1931327,1688512,1828096,1603621,1735000,1523384,1646608,1452862,1563894,1386331,1487586,1320447,1420407,1265884,1355113,1211841,1295332,1161989,1238282,1114927,1186918,1072409,1135479,1034770,1091431,997182,1050869,963398,1008932,933383,973547,902972,939221,877933,907715,851195,876962,825853,848225,804809,818805,783712,792994,765063,767005,750435,745417,734880,722293,721918,700870,710671,678511,697871,659889,688367,640648,679564,620449,670553,603031,875550,610759,1063717,615479,1028599,589957,992095,565814,960957,540335,928279,519599,897352,498592,866879,480292,839276,459937,811359,442661,785004,423731,761996,408680,739625,392501,718562,377533,698011,362380,677749,347237,662418,333736,644681,320601,631056,308824,616745,296557,603494,286074,593268,275211,581252,264325,573063,253953,562776,244201,551650,234739,544269,224986,536609,216510,525909,207987,519040,200459,512154,191947,504695,184563,497441,177030,488008,170136,479262,162776,472870,155737,465554,150475,456870,143638,449293,137978,440371,131676,432423,125657,423864,120685,415857,115120,408326,110817,399305,104738,390809,99794,382829,94773,372234,90534,362971,85714,355570,80663,345104,77021,336166,72742,326705,68455,317554,64383,307519,59844,298666,56256,290764,52430,281497,49271,272144,46573,264983,42964,256042,40035,246129,36888,239546,34103,230020,47839,115843,
};
SRLA_STATIC_ASSERT((1 << SRLA_LPC_COEFFICIENT_BITWIDTH) == SRLA_NUM_ARRAY_ELEMENTS(g_parameter_frequency_table));

/* マージンリスト候補配列 */
static const double margin_list[] = { 0.0, 1.0 / 4096, 1.0 / 1024, 1.0 / 256, 1.0 / 64, 1.0 / 16 };

/* パラメータプリセット配列 */
const struct SRLAParameterPreset g_srla_parameter_preset[] = {
    {  32, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_MAX_FIXED,  0, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    {  32, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_MAX_FIXED, 10, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    {  32, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_BRUTEFORCE_ESTIMATION,  0, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    {  32, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_BRUTEFORCE_ESTIMATION, 10, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    {  32, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_BRUTEFORCE_SEARCH,  0, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    {  32, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_BRUTEFORCE_SEARCH, 10, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    {  64, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_MAX_FIXED,  0, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    {  64, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_MAX_FIXED, 10, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    {  64, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_BRUTEFORCE_ESTIMATION,  0, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    {  64, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_BRUTEFORCE_ESTIMATION, 10, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    { 128, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_MAX_FIXED,  0, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    { 128, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_MAX_FIXED, 10, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    { 128, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_BRUTEFORCE_ESTIMATION,  0, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
    { 128, SRLA_CH_PROCESS_METHOD_TACTICS_ADAPTIVE, SRLA_LPC_ORDER_DECISION_TACTICS_BRUTEFORCE_ESTIMATION, 10, SRLA_DEFINE_ARRAY_AND_NUM_ELEMTNS_TUPLE(margin_list) },
};

SRLA_STATIC_ASSERT(SRLA_NUM_ARRAY_ELEMENTS(g_srla_parameter_preset) == SRLA_NUM_PARAMETER_PRESETS);
