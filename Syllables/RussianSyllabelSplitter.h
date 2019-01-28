#pragma once
#include "SyllabelSplitter.h"
class RussianSyllabelSplitter :
    public SyllabelSplitter
{
public:
    RussianSyllabelSplitter() :
        SyllabelSplitter("àÀåÅ¸¨èÈîÎóÓûÛıİşŞÿß", "àáâãäå¸æçèêëìíîïğñòóôõö÷øùüûúışÿÀÁÂÃÄÅ¨ÆÇÈÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÜÛÚİŞß")
    {}
};
