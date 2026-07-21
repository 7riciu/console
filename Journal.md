---
title: "Console"
author: "Patricia Tepordei"
description: "Game console"
created_at: "2026-05-09"
---

# May 9th: Setting everything up!

[I started my first ever hardware project by following the Fallout tamagotchi tutorial.
After installing all of the apps, I learned how to import libraries into KiCad. I had some errors and confusion with the way files were being stored, but I eventually sorted it out.
I learned to import certaing parts using EasyEDA2KiCad.
I imported the XIAO-ESP32-C3 as the MCU and the display: HS96L03W2C03, and wired everything together.]

[picture](hc1.png)

**Total time spent: 1.6h**


# May 12th: Schematics!

[I continued to follow through with the tutorial and finished making the schematics.
I added the 3 buttons for the tamagotchi, a buzzer and the battery.
Then I assigned the correct footprints for everything.]

[picture](hc2.png)

**Total time spent: 0.64h**


# June 13th: Starting with the PCB!

[After sorting out the footprints, I passed to the PCB!
I was very confused with pins throughout the whole session. I was following the tutorial steps and also surfing the Internet in order to figure things out.
Also, I drew out a vague shape of the tamagotchi just to get a reference of how things should be arrange and how the PCB cutout works. Later on I realised I made the lines on the wrong layer.]

[picture](hc3.png)

**Total time spent: 0.81h**


# June 14th: Continuing with the PCB!

[After some (off-camera) reading and documentation, I understood how pins and footprints worked and fixed all of the errors I was strugling with.
This is the day I realised I didn't draw the PCB outlines on the Edge.Cuts layer so I fixed that. I learned to use the measureing tool and created more accurate proportions for a tamagotchi. Also, I added some mounting holes and learned about their purpose.]

[picture](hc4.png)

**Total time spent: 0.67h**


# June 14th: Switching the direction of the project towards something more personal!

[I decided to create a console you could play a game on (something simple like snake bite or maze escape). I wanted it to have a cute heart-shaped case. I spent some time sketching out my idea.]

[picture](hc6.png)

[I then starting making my new schematic. This was very scary to me. I felt very uncertain in picking parts on my own and I did some reasearch for tips and advice. I was in doubt about wiring things together too because I wasnt sure what I am and not allowed to do.
I eventually mapped all of the components out and made a schematic that atched my vision. I had 8 buttons: 4 for a D-pad on the left side of the console, 2 for controlls on the right side and 2 on the top or bottom part of the screen for other functionalities (Turn on/off, select).]

[picture](hc5.png)

**Total time spent: 1.05h**


# June 14th: Changing the display!

[Since I was making a console, I thought I would need a larger display. I changed it twice until I settled down.
I took into consideration the size of the screen itself, the size of the whole piece, so it would fit the targeted size of the PCB and the console, the color of the LEDs. After a lot of back-and-forth, I decided to use an HS145L03W2C01 because it seemed to fit best the proportions I was going for.
I then made a rectangular shape for the PCB and vaguely arranged the components.]

[picture](hc7.png)

**Total time spent: 1.18h**


# June 16th: Routing!

[I went through the basics of routing.
I read some documentaion on how it works and temporaryly routed my PCB. It probably wasn't very good, but I knew I still wanted to make changes to the layout, so I didn't polish it at this stage.]

[picture](hc8.png)

**Total time spent: 0.38h**


# June 16th: Paper prototype!

[Since I've never worked with hardware before, it was hard for me to visualise what I was doing on my computer into a real product. So I decided to make a paper prototype of the console in order to get accurate proportions.
I used the datasheets to get the sizes of each part and I drew them using their actual size. I used this paper model as a reference for everything I did after this from the PCB to the CAD.]

[paper model](hc9.png)
[rearranged PCB using the paper model](hc10.png)

**Total time spent: 1.42h**


# June 16th (and 17th): Routing the console PCB!

[After rearranging the PCB according to the paper model proportion, I started routing once again! And it was so so bad.
I once again was feeling so uncertain because I didn't know what was normal and what was not. Also, I was getting a bunch of violations in the DRC scan and I had no idea what they meant. I was taking it methodically and slowly I managed to them all (some mounting holes were not assignded as mounting holes, the F.Courtyard layer of the buzzer was too small)
I'm not sure if I did the right thing, but I read that warnings could be ignored and I should only focus on errors so that's what I did.]

[DRC violations](hc11.png)

**Total time spent: 2.53h**


# June 17th: Onshape PCB import!

[On the 17th I started learning CAD design using Onshape.
First of all, I followed a little YouTube tutorial in the scope of getting the basics down.
I learned to export the PCB from KiCad and I was getting errors when importing it into Onshape. I did a lot of reading and looking through the datasheets (I didn't know what was going wrong and where to find answers). Eventually I realligned the display on the component inside KiCad manually (probably not the best way) and it showed up properly in Onshape.]

[Onshape PCB import errors](hc12.png)
[fixed Onshape PCB](hc13.png)

**Total time spent: 1.55h**


# June 17th: Onshape CAD!

[I started making the actual 3D design for the case! I made the main shape of the console and made it thicker using the Extrude tool.]

[Simple shape](hc14.png)

[Here I noticed that the buzzer and the battery were sticking out awkwardly. I decided to move the buzzer in the back of the PCB (where the battery was as well) so that the front of the case can stay close to the screen display.]

[PCB side-view](hc15.png)

[I was making sure everything is proportinate. I then rounded/smoothed out all of the edges, made the cutouts for the buttons and the screen display and changes the color of the case to pink.
I also realised I need to change the arrangement of the PCB once again because the buttons dont line up nicely with the button-cap holes.]

[current product](hc16.png)

**Total time spent: 3.38h**


# More progress coming soon!

[My console is still a work-in-progress and I'm looking forward to finishing it! 
I'm really sorry for not being able to provide a finished product before the IRL Horizons Europa event, but I hope the progress I've made so far is enough to pass review and get me a ticket to the event <3
I will continue working and learning!]