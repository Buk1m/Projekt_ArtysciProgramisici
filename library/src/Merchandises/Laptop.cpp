//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Merchandises/Laptop.h"
#include "../../include/Components/Processor.h"
#include "../../include/Components/GraphicCard.h"
#include "../../include/Components/DiskDrive.h"
#include "../../include/Components/Display.h"
#include "../../include/Components/Ram.h"

Laptop::Laptop(const string &name, float price, int quantity, const shared_ptr<Processor> &processor,
               const shared_ptr<GraphicCard> &graphicCard, const shared_ptr<Ram> &ram,
               const shared_ptr<DiskDrive> &discDrive, const shared_ptr<Display> &display)
       : Merchandise(name, price, quantity),
         processor(processor),
         graphicCard(graphicCard),
         ram(ram),
         discDrive(discDrive),
         display(display)
{}
