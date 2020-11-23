//----------------------------------------------------------
// name: "mTDelHarmo7B"
//
// Code generated with Faust 0.9.98 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>
/************************************************************************

    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2004-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either version 3
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

    MAX MSP SDK : in order to compile a MaxMSP external with this
    architecture file you will need the official MaxMSP SDK from
    cycling'74. Please check the corresponding license.

 ************************************************************************
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef __APPLE__
#include <Carbon/Carbon.h>
#include <unistd.h>
#endif

#ifdef WIN32
#ifndef NAN
    static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
    #define NAN (*(const float *) __nan)
#endif
#endif

#define FAUSTFLOAT double

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <assert.h>

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

class JSONUI : public PathBuilder, public Meta, public UI
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fName;
        std::string fExpandedCode;
        std::string fSHAKey;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
        
        void init(const std::string& name, int inputs, int outputs, const std::string& sha_key, const std::string& dsp_code)
        {
            fTab = 1;
            
            // Start Meta generation
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fInputs = inputs;
            fOutputs = outputs;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
        }
        
        inline std::string flatten(const std::string& src)
        {
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        dst << ' ';
                        break;
                    case '"':
                        dst << "\\" << '"';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
      
     public:
     
        JSONUI(const std::string& name, int inputs, int outputs, const std::string& sha_key, const std::string& dsp_code)
        {
            init(name, inputs, outputs, sha_key, dsp_code);
        }

        JSONUI(const std::string& name, int inputs, int outputs)
        {
            init(name, inputs, outputs, "", "");
        }

        JSONUI(int inputs, int outputs)
        {
            init("", inputs, outputs, "", "");
        }
        
        JSONUI()
        {
            init("", -1, -1, "", "");
        }
 
        virtual ~JSONUI() {}

        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            fControlsLevel.push_back(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab + 1);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            fControlsLevel.pop_back();
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
    
        virtual void addGenericButton(const char* label, const char* name)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ",";
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ",";
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
            if (fSHAKey != "") { tab(fTab, fJSON); fJSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, fJSON); fJSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, fJSON); fJSON << "\"inputs\": \"" << fInputs << "\","; 
            tab(fTab, fJSON); fJSON << "\"outputs\": \"" << fOutputs << "\",";
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                fJSON << fMeta.str() << fUI.str();
            } else {
                fJSON << fUI.str();
            }
            tab(fTab, fJSON); fJSON << "}" << std::endl;
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

#endif // FAUST_JSONUI_H
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the UI* parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the UI* user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /** Global init, calls the following methods:
         * - static class 'classInit': static table initialisation
         * - 'instanceInit': constants and instance table initialisation
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void init(int samplingRate) = 0;
    
        /** Init instance state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceInit(int samplingRate) = 0;
    
        /** Init instance constant state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
    
        /**  
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value metadata).
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with sucessive in/out audio buffers.
         *
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { return fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


#ifdef POLY2
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <assert.h>

// Combine two DSP in sequence

class dsp_sequencer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
        FAUSTFLOAT** fSeqBuffer;
         
    public:
        
        dsp_sequencer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            assert(fDSP1->getNumOutputs() == fDSP2->getNumInputs());
            fSeqBuffer = new FAUSTFLOAT*[fDSP1->getNumOutputs()];
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
                fSeqBuffer[i] = new FAUSTFLOAT[buffer_size];
            }
        }
        
        virtual ~dsp_sequencer()
        {
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
               delete [] fSeqBuffer[i];
            }
            
            delete [] fSeqBuffer;
            delete fDSP1;
            delete fDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Sequencer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
    
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }
    
        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
        
        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone());
        }
    
        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
 
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fSeqBuffer);
            fDSP2->compute(count, fSeqBuffer, outputs);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
         
    public:
        
        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {}
        
        virtual ~dsp_parallelizer()
        {
            delete fDSP1;
            delete fDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Parallelizer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
        
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }
    
        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
        
        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);
            
            // Shift inputs/outputs channels for fDSP2
            FAUSTFLOAT** inputs_dsp2 = (FAUSTFLOAT**)alloca(fDSP2->getNumInputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                inputs_dsp2[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            
            FAUSTFLOAT** outputs_dsp2 = (FAUSTFLOAT**)alloca(fDSP2->getNumOutputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                outputs_dsp2[chan] = inputs[fDSP1->getNumOutputs() + chan];
            }
            
            fDSP2->compute(count, inputs_dsp2, outputs_dsp2);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

#endif
#include "effect.cpp"
#endif

using namespace std;

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	class SIG0 {
	  private:
		int fSamplingFreq;
		int 	iRec7[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			for (int i=0; i<2; i++) iRec7[i] = 0;
		}
		void fill (int count, double output[]) {
			for (int i=0; i<count; i++) {
				iRec7[0] = (iRec7[1] + 1);
				output[i] = sin((9.587379924285257e-05 * double((iRec7[0] + -1))));
				// post processing
				iRec7[1] = iRec7[0];
			}
		}
	};


	static double 	ftbl0[65536];
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fRec8[2];
	double 	fVec0[2];
	FAUSTFLOAT 	fslider0;
	double 	fConst3;
	FAUSTFLOAT 	fslider1;
	double 	fRec9[2];
	FAUSTFLOAT 	fcheckbox0;
	FAUSTFLOAT 	fslider2;
	double 	fRec10[2];
	FAUSTFLOAT 	fcheckbox1;
	FAUSTFLOAT 	fslider3;
	double 	fRec11[2];
	FAUSTFLOAT 	fcheckbox2;
	FAUSTFLOAT 	fslider4;
	double 	fRec12[2];
	FAUSTFLOAT 	fcheckbox3;
	FAUSTFLOAT 	fslider5;
	double 	fRec13[2];
	FAUSTFLOAT 	fcheckbox4;
	FAUSTFLOAT 	fslider6;
	double 	fRec14[2];
	FAUSTFLOAT 	fcheckbox5;
	FAUSTFLOAT 	fslider7;
	double 	fRec15[2];
	FAUSTFLOAT 	fcheckbox6;
	FAUSTFLOAT 	fslider8;
	double 	fRec16[2];
	int 	IOTA;
	double 	fVec1[1048576];
	double 	fConst4;
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	int 	iRec17[2];
	double 	fVec2[2];
	int 	iRec18[2];
	double 	fVec3[262144];
	double 	fConst5;
	FAUSTFLOAT 	fslider11;
	FAUSTFLOAT 	fslider12;
	FAUSTFLOAT 	fslider13;
	double 	fVec4[2];
	double 	fConst6;
	double 	fRec21[2];
	double 	fRec22[2];
	double 	fRec20[2];
	double 	fVec5[2];
	double 	fRec19[2];
	double 	fVec6[2];
	double 	fRec23[2];
	double 	fVec7[2];
	double 	fRec24[2];
	double 	fVec8[2];
	double 	fRec25[2];
	double 	fRec0[2];
	FAUSTFLOAT 	fslider14;
	double 	fRec26[2];
	FAUSTFLOAT 	fcheckbox7;
	FAUSTFLOAT 	fcheckbox8;
	FAUSTFLOAT 	fcheckbox9;
	FAUSTFLOAT 	fcheckbox10;
	FAUSTFLOAT 	fcheckbox11;
	FAUSTFLOAT 	fcheckbox12;
	FAUSTFLOAT 	fcheckbox13;
	double 	fVec9[1048576];
	FAUSTFLOAT 	fslider15;
	int 	iRec27[2];
	int 	iRec28[2];
	double 	fVec10[262144];
	FAUSTFLOAT 	fslider16;
	FAUSTFLOAT 	fslider17;
	double 	fRec30[2];
	double 	fVec11[2];
	double 	fRec29[2];
	double 	fVec12[2];
	double 	fRec31[2];
	double 	fVec13[2];
	double 	fRec32[2];
	double 	fVec14[2];
	double 	fRec33[2];
	double 	fRec1[2];
	FAUSTFLOAT 	fslider18;
	double 	fRec34[2];
	FAUSTFLOAT 	fcheckbox14;
	FAUSTFLOAT 	fcheckbox15;
	FAUSTFLOAT 	fcheckbox16;
	FAUSTFLOAT 	fcheckbox17;
	FAUSTFLOAT 	fcheckbox18;
	FAUSTFLOAT 	fcheckbox19;
	FAUSTFLOAT 	fcheckbox20;
	double 	fVec15[1048576];
	FAUSTFLOAT 	fslider19;
	int 	iRec35[2];
	int 	iRec36[2];
	double 	fVec16[262144];
	FAUSTFLOAT 	fslider20;
	FAUSTFLOAT 	fslider21;
	double 	fRec38[2];
	double 	fVec17[2];
	double 	fRec37[2];
	double 	fVec18[2];
	double 	fRec39[2];
	double 	fVec19[2];
	double 	fRec40[2];
	double 	fVec20[2];
	double 	fRec41[2];
	double 	fRec2[2];
	FAUSTFLOAT 	fslider22;
	double 	fRec42[2];
	FAUSTFLOAT 	fcheckbox21;
	FAUSTFLOAT 	fcheckbox22;
	FAUSTFLOAT 	fcheckbox23;
	FAUSTFLOAT 	fcheckbox24;
	FAUSTFLOAT 	fcheckbox25;
	FAUSTFLOAT 	fcheckbox26;
	FAUSTFLOAT 	fcheckbox27;
	double 	fVec21[1048576];
	FAUSTFLOAT 	fslider23;
	int 	iRec43[2];
	int 	iRec44[2];
	double 	fVec22[262144];
	FAUSTFLOAT 	fslider24;
	FAUSTFLOAT 	fslider25;
	double 	fRec46[2];
	double 	fVec23[2];
	double 	fRec45[2];
	double 	fVec24[2];
	double 	fRec47[2];
	double 	fVec25[2];
	double 	fRec48[2];
	double 	fVec26[2];
	double 	fRec49[2];
	double 	fRec3[2];
	FAUSTFLOAT 	fslider26;
	double 	fRec50[2];
	FAUSTFLOAT 	fcheckbox28;
	FAUSTFLOAT 	fcheckbox29;
	FAUSTFLOAT 	fcheckbox30;
	FAUSTFLOAT 	fcheckbox31;
	FAUSTFLOAT 	fcheckbox32;
	FAUSTFLOAT 	fcheckbox33;
	FAUSTFLOAT 	fcheckbox34;
	double 	fVec27[1048576];
	FAUSTFLOAT 	fslider27;
	int 	iRec51[2];
	int 	iRec52[2];
	double 	fVec28[262144];
	FAUSTFLOAT 	fslider28;
	FAUSTFLOAT 	fslider29;
	double 	fRec54[2];
	double 	fVec29[2];
	double 	fRec53[2];
	double 	fVec30[2];
	double 	fRec55[2];
	double 	fVec31[2];
	double 	fRec56[2];
	double 	fVec32[2];
	double 	fRec57[2];
	double 	fRec4[2];
	FAUSTFLOAT 	fslider30;
	double 	fRec58[2];
	FAUSTFLOAT 	fcheckbox35;
	FAUSTFLOAT 	fcheckbox36;
	FAUSTFLOAT 	fcheckbox37;
	FAUSTFLOAT 	fcheckbox38;
	FAUSTFLOAT 	fcheckbox39;
	FAUSTFLOAT 	fcheckbox40;
	FAUSTFLOAT 	fcheckbox41;
	double 	fVec33[1048576];
	FAUSTFLOAT 	fslider31;
	int 	iRec59[2];
	int 	iRec60[2];
	double 	fVec34[262144];
	FAUSTFLOAT 	fslider32;
	FAUSTFLOAT 	fslider33;
	double 	fRec62[2];
	double 	fVec35[2];
	double 	fRec61[2];
	double 	fVec36[2];
	double 	fRec63[2];
	double 	fVec37[2];
	double 	fRec64[2];
	double 	fVec38[2];
	double 	fRec65[2];
	double 	fRec5[2];
	FAUSTFLOAT 	fslider34;
	double 	fRec66[2];
	FAUSTFLOAT 	fcheckbox42;
	FAUSTFLOAT 	fcheckbox43;
	FAUSTFLOAT 	fcheckbox44;
	FAUSTFLOAT 	fcheckbox45;
	FAUSTFLOAT 	fcheckbox46;
	FAUSTFLOAT 	fcheckbox47;
	FAUSTFLOAT 	fcheckbox48;
	double 	fVec39[1048576];
	FAUSTFLOAT 	fslider35;
	int 	iRec67[2];
	int 	iRec68[2];
	double 	fVec40[262144];
	FAUSTFLOAT 	fslider36;
	FAUSTFLOAT 	fslider37;
	double 	fRec70[2];
	double 	fVec41[2];
	double 	fRec69[2];
	double 	fVec42[2];
	double 	fRec71[2];
	double 	fVec43[2];
	double 	fRec72[2];
	double 	fVec44[2];
	double 	fRec73[2];
	double 	fRec6[2];
	FAUSTFLOAT 	fslider38;
	double 	fRec74[2];
	FAUSTFLOAT 	fslider39;
	double 	fRec75[2];
	FAUSTFLOAT 	fslider40;
	double 	fRec76[2];
	FAUSTFLOAT 	fslider41;
	double 	fRec77[2];
	FAUSTFLOAT 	fslider42;
	double 	fRec78[2];
	FAUSTFLOAT 	fslider43;
	double 	fRec79[2];
	FAUSTFLOAT 	fslider44;
	double 	fRec80[2];
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("compilation_options", "-single -scal");
		m->declare("library_path", "mTDelHarmo7B");
		m->declare("basics_lib_name", "Faust Basic Element Library");
		m->declare("basics_lib_version", "0.0");
		m->declare("delays_lib_name", "Faust Delay Library");
		m->declare("delays_lib_version", "0.0");
		m->declare("maths_lib_author", "GRAME");
		m->declare("maths_lib_copyright", "GRAME");
		m->declare("maths_lib_license", "LGPL with exception");
		m->declare("maths_lib_name", "Faust Math Library");
		m->declare("maths_lib_version", "2.0");
		m->declare("name", "mTDelHarmo7B");
		m->declare("oscillators_lib_name", "Faust Oscillator Library");
		m->declare("oscillators_lib_version", "0.0");
		m->declare("signals_lib_name", "Faust Signal Routing Library");
		m->declare("signals_lib_version", "0.0");
	}

	virtual int getNumInputs() { return 7; }
	virtual int getNumOutputs() { return 7; }
	static void classInit(int samplingFreq) {
		SIG0 sig0;
		sig0.init(samplingFreq);
		sig0.fill(65536,ftbl0);
	}
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(1.92e+05, max(1.0, (double)fSamplingFreq));
		fConst1 = double(fConst0);
		fConst2 = (double(30) / fConst1);
		fConst3 = (1e+03 / fConst0);
		fConst4 = (0.001 * fConst0);
		fConst5 = (1.0 / fConst1);
		fConst6 = (0.03 * fConst0);
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 1.0;
		fslider1 = 2e+01;
		fcheckbox0 = 0.0;
		fslider2 = 0.0;
		fcheckbox1 = 0.0;
		fslider3 = 0.0;
		fcheckbox2 = 0.0;
		fslider4 = 0.0;
		fcheckbox3 = 0.0;
		fslider5 = 0.0;
		fcheckbox4 = 0.0;
		fslider6 = 0.0;
		fcheckbox5 = 0.0;
		fslider7 = 0.0;
		fcheckbox6 = 0.0;
		fslider8 = 0.0;
		fslider9 = 1.0;
		fslider10 = 1e+02;
		fslider11 = 0.0;
		fslider12 = 1.0;
		fslider13 = 64.0;
		fslider14 = 1.0;
		fcheckbox7 = 0.0;
		fcheckbox8 = 0.0;
		fcheckbox9 = 0.0;
		fcheckbox10 = 0.0;
		fcheckbox11 = 0.0;
		fcheckbox12 = 0.0;
		fcheckbox13 = 0.0;
		fslider15 = 2e+02;
		fslider16 = 0.0;
		fslider17 = 1.0;
		fslider18 = 1.0;
		fcheckbox14 = 0.0;
		fcheckbox15 = 0.0;
		fcheckbox16 = 0.0;
		fcheckbox17 = 0.0;
		fcheckbox18 = 0.0;
		fcheckbox19 = 0.0;
		fcheckbox20 = 0.0;
		fslider19 = 3e+02;
		fslider20 = 0.0;
		fslider21 = 1.0;
		fslider22 = 1.0;
		fcheckbox21 = 0.0;
		fcheckbox22 = 0.0;
		fcheckbox23 = 0.0;
		fcheckbox24 = 0.0;
		fcheckbox25 = 0.0;
		fcheckbox26 = 0.0;
		fcheckbox27 = 0.0;
		fslider23 = 4e+02;
		fslider24 = 0.0;
		fslider25 = 1.0;
		fslider26 = 1.0;
		fcheckbox28 = 0.0;
		fcheckbox29 = 0.0;
		fcheckbox30 = 0.0;
		fcheckbox31 = 0.0;
		fcheckbox32 = 0.0;
		fcheckbox33 = 0.0;
		fcheckbox34 = 0.0;
		fslider27 = 5e+02;
		fslider28 = 0.0;
		fslider29 = 1.0;
		fslider30 = 1.0;
		fcheckbox35 = 0.0;
		fcheckbox36 = 0.0;
		fcheckbox37 = 0.0;
		fcheckbox38 = 0.0;
		fcheckbox39 = 0.0;
		fcheckbox40 = 0.0;
		fcheckbox41 = 0.0;
		fslider31 = 6e+02;
		fslider32 = 0.0;
		fslider33 = 1.0;
		fslider34 = 1.0;
		fcheckbox42 = 0.0;
		fcheckbox43 = 0.0;
		fcheckbox44 = 0.0;
		fcheckbox45 = 0.0;
		fcheckbox46 = 0.0;
		fcheckbox47 = 0.0;
		fcheckbox48 = 0.0;
		fslider35 = 7e+02;
		fslider36 = 0.0;
		fslider37 = 1.0;
		fslider38 = 1.0;
		fslider39 = 1.0;
		fslider40 = 1.0;
		fslider41 = 1.0;
		fslider42 = 1.0;
		fslider43 = 1.0;
		fslider44 = 1.0;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		IOTA = 0;
		for (int i=0; i<1048576; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iRec17[i] = 0;
		for (int i=0; i<2; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<262144; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<1048576; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iRec27[i] = 0;
		for (int i=0; i<2; i++) iRec28[i] = 0;
		for (int i=0; i<262144; i++) fVec10[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fVec12[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fVec14[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<1048576; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) iRec35[i] = 0;
		for (int i=0; i<2; i++) iRec36[i] = 0;
		for (int i=0; i<262144; i++) fVec16[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fVec18[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fVec20[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<1048576; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iRec43[i] = 0;
		for (int i=0; i<2; i++) iRec44[i] = 0;
		for (int i=0; i<262144; i++) fVec22[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fVec24[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fVec25[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fVec26[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<1048576; i++) fVec27[i] = 0;
		for (int i=0; i<2; i++) iRec51[i] = 0;
		for (int i=0; i<2; i++) iRec52[i] = 0;
		for (int i=0; i<262144; i++) fVec28[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fVec29[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fVec30[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fVec31[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fVec32[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<1048576; i++) fVec33[i] = 0;
		for (int i=0; i<2; i++) iRec59[i] = 0;
		for (int i=0; i<2; i++) iRec60[i] = 0;
		for (int i=0; i<262144; i++) fVec34[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fVec35[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fVec36[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fVec37[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fVec38[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<1048576; i++) fVec39[i] = 0;
		for (int i=0; i<2; i++) iRec67[i] = 0;
		for (int i=0; i<2; i++) iRec68[i] = 0;
		for (int i=0; i<262144; i++) fVec40[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fVec41[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fVec42[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fVec43[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fVec44[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
	}
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("0x00");
		ui_interface->openHorizontalBox("Global_Parameters");
		ui_interface->declare(&fslider9, "7", "");
		ui_interface->addHorizontalSlider("dStretch", &fslider9, 1.0, 0.01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("hWin", &fslider13, 64.0, 1.0, 127.0, 0.01);
		ui_interface->addHorizontalSlider("smoothDuration", &fslider1, 2e+01, 1e+01, 5e+03, 1.0);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Lines");
		ui_interface->openVerticalBox("Del_Durations");
		ui_interface->addHorizontalSlider("d 0", &fslider10, 1e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 1", &fslider15, 2e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 2", &fslider19, 3e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 3", &fslider23, 4e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 4", &fslider27, 5e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 5", &fslider31, 6e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 6", &fslider35, 7e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del_Feedbacks");
		ui_interface->addHorizontalSlider("fd 0", &fslider2, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 1", &fslider3, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 2", &fslider4, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 3", &fslider5, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 4", &fslider6, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 5", &fslider7, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 6", &fslider8, 0.0, 0.0, 0.99, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Harmo_Transpositions");
		ui_interface->addHorizontalSlider("tr 0", &fslider11, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 1", &fslider16, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 2", &fslider20, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 3", &fslider24, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 4", &fslider28, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 5", &fslider32, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 6", &fslider36, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Line_input");
		ui_interface->declare(&fslider0, "5", "");
		ui_interface->addHorizontalSlider("inp 0", &fslider0, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider14, "5", "");
		ui_interface->addHorizontalSlider("inp 1", &fslider14, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider18, "5", "");
		ui_interface->addHorizontalSlider("inp 2", &fslider18, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider22, "5", "");
		ui_interface->addHorizontalSlider("inp 3", &fslider22, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider26, "5", "");
		ui_interface->addHorizontalSlider("inp 4", &fslider26, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider30, "5", "");
		ui_interface->addHorizontalSlider("inp 5", &fslider30, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider34, "5", "");
		ui_interface->addHorizontalSlider("inp 6", &fslider34, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Line_output");
		ui_interface->declare(&fslider38, "6", "");
		ui_interface->addHorizontalSlider("out 0", &fslider38, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider39, "6", "");
		ui_interface->addHorizontalSlider("out 1", &fslider39, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider40, "6", "");
		ui_interface->addHorizontalSlider("out 2", &fslider40, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider41, "6", "");
		ui_interface->addHorizontalSlider("out 3", &fslider41, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider42, "6", "");
		ui_interface->addHorizontalSlider("out 4", &fslider42, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider43, "6", "");
		ui_interface->addHorizontalSlider("out 5", &fslider43, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider44, "6", "");
		ui_interface->addHorizontalSlider("out 6", &fslider44, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Reinjection_Matrix");
		ui_interface->openVerticalBox("Del 0-->");
		ui_interface->addCheckButton("r  0", &fcheckbox0);
		ui_interface->addCheckButton("r  7", &fcheckbox7);
		ui_interface->addCheckButton("r 14", &fcheckbox14);
		ui_interface->addCheckButton("r 21", &fcheckbox21);
		ui_interface->addCheckButton("r 28", &fcheckbox28);
		ui_interface->addCheckButton("r 35", &fcheckbox35);
		ui_interface->addCheckButton("r 42", &fcheckbox42);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 1-->");
		ui_interface->addCheckButton("r  1", &fcheckbox1);
		ui_interface->addCheckButton("r  8", &fcheckbox8);
		ui_interface->addCheckButton("r 15", &fcheckbox15);
		ui_interface->addCheckButton("r 22", &fcheckbox22);
		ui_interface->addCheckButton("r 29", &fcheckbox29);
		ui_interface->addCheckButton("r 36", &fcheckbox36);
		ui_interface->addCheckButton("r 43", &fcheckbox43);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 2-->");
		ui_interface->addCheckButton("r  2", &fcheckbox2);
		ui_interface->addCheckButton("r  9", &fcheckbox9);
		ui_interface->addCheckButton("r 16", &fcheckbox16);
		ui_interface->addCheckButton("r 23", &fcheckbox23);
		ui_interface->addCheckButton("r 30", &fcheckbox30);
		ui_interface->addCheckButton("r 37", &fcheckbox37);
		ui_interface->addCheckButton("r 44", &fcheckbox44);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 3-->");
		ui_interface->addCheckButton("r  3", &fcheckbox3);
		ui_interface->addCheckButton("r 10", &fcheckbox10);
		ui_interface->addCheckButton("r 17", &fcheckbox17);
		ui_interface->addCheckButton("r 24", &fcheckbox24);
		ui_interface->addCheckButton("r 31", &fcheckbox31);
		ui_interface->addCheckButton("r 38", &fcheckbox38);
		ui_interface->addCheckButton("r 45", &fcheckbox45);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 4-->");
		ui_interface->addCheckButton("r  4", &fcheckbox4);
		ui_interface->addCheckButton("r 11", &fcheckbox11);
		ui_interface->addCheckButton("r 18", &fcheckbox18);
		ui_interface->addCheckButton("r 25", &fcheckbox25);
		ui_interface->addCheckButton("r 32", &fcheckbox32);
		ui_interface->addCheckButton("r 39", &fcheckbox39);
		ui_interface->addCheckButton("r 46", &fcheckbox46);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 5-->");
		ui_interface->addCheckButton("r  5", &fcheckbox5);
		ui_interface->addCheckButton("r 12", &fcheckbox12);
		ui_interface->addCheckButton("r 19", &fcheckbox19);
		ui_interface->addCheckButton("r 26", &fcheckbox26);
		ui_interface->addCheckButton("r 33", &fcheckbox33);
		ui_interface->addCheckButton("r 40", &fcheckbox40);
		ui_interface->addCheckButton("r 47", &fcheckbox47);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 6-->");
		ui_interface->addCheckButton("r  6", &fcheckbox6);
		ui_interface->addCheckButton("r 13", &fcheckbox13);
		ui_interface->addCheckButton("r 20", &fcheckbox20);
		ui_interface->addCheckButton("r 27", &fcheckbox27);
		ui_interface->addCheckButton("r 34", &fcheckbox34);
		ui_interface->addCheckButton("r 41", &fcheckbox41);
		ui_interface->addCheckButton("r 48", &fcheckbox48);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Stretch");
		ui_interface->addHorizontalSlider("hStretch 0", &fslider12, 1.0, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("hStretch 1", &fslider17, 1.0, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("hStretch 2", &fslider21, 1.0, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("hStretch 3", &fslider25, 1.0, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("hStretch 4", &fslider29, 1.0, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("hStretch 5", &fslider33, 1.0, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("hStretch 6", &fslider37, 1.0, -1e+01, 1e+01, 0.01);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		double 	fSlow0 = exp((0 - (fConst3 / double(fslider1))));
		double 	fSlow1 = (1.0 - fSlow0);
		double 	fSlow2 = (double(fslider0) * fSlow1);
		double 	fSlow3 = double(fcheckbox0);
		double 	fSlow4 = (double(fslider2) * fSlow1);
		double 	fSlow5 = double(fcheckbox1);
		double 	fSlow6 = (double(fslider3) * fSlow1);
		double 	fSlow7 = double(fcheckbox2);
		double 	fSlow8 = (double(fslider4) * fSlow1);
		double 	fSlow9 = double(fcheckbox3);
		double 	fSlow10 = (double(fslider5) * fSlow1);
		double 	fSlow11 = double(fcheckbox4);
		double 	fSlow12 = (double(fslider6) * fSlow1);
		double 	fSlow13 = double(fcheckbox5);
		double 	fSlow14 = (double(fslider7) * fSlow1);
		double 	fSlow15 = double(fcheckbox6);
		double 	fSlow16 = (double(fslider8) * fSlow1);
		double 	fSlow17 = double(fslider9);
		int 	iSlow18 = int((fConst4 * (fSlow17 * double(fslider10))));
		double 	fSlow19 = (fConst5 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((double(fslider11) * double(fslider12)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow20 = double(fslider13);
		double 	fSlow21 = ((int((fSlow20 < 127)))?fSlow20:127);
		double 	fSlow22 = ((int((fSlow21 < 1)))?0:(4096 * pow(1.07177,(fSlow21 + -127))));
		double 	fSlow23 = (double(fslider14) * fSlow1);
		double 	fSlow24 = double(fcheckbox7);
		double 	fSlow25 = double(fcheckbox8);
		double 	fSlow26 = double(fcheckbox9);
		double 	fSlow27 = double(fcheckbox10);
		double 	fSlow28 = double(fcheckbox11);
		double 	fSlow29 = double(fcheckbox12);
		double 	fSlow30 = double(fcheckbox13);
		int 	iSlow31 = int((fConst4 * (fSlow17 * double(fslider15))));
		double 	fSlow32 = (fConst5 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((double(fslider16) * double(fslider17)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow33 = (double(fslider18) * fSlow1);
		double 	fSlow34 = double(fcheckbox14);
		double 	fSlow35 = double(fcheckbox15);
		double 	fSlow36 = double(fcheckbox16);
		double 	fSlow37 = double(fcheckbox17);
		double 	fSlow38 = double(fcheckbox18);
		double 	fSlow39 = double(fcheckbox19);
		double 	fSlow40 = double(fcheckbox20);
		int 	iSlow41 = int((fConst4 * (fSlow17 * double(fslider19))));
		double 	fSlow42 = (fConst5 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((double(fslider20) * double(fslider21)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow43 = (double(fslider22) * fSlow1);
		double 	fSlow44 = double(fcheckbox21);
		double 	fSlow45 = double(fcheckbox22);
		double 	fSlow46 = double(fcheckbox23);
		double 	fSlow47 = double(fcheckbox24);
		double 	fSlow48 = double(fcheckbox25);
		double 	fSlow49 = double(fcheckbox26);
		double 	fSlow50 = double(fcheckbox27);
		int 	iSlow51 = int((fConst4 * (fSlow17 * double(fslider23))));
		double 	fSlow52 = (fConst5 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((double(fslider24) * double(fslider25)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow53 = (double(fslider26) * fSlow1);
		double 	fSlow54 = double(fcheckbox28);
		double 	fSlow55 = double(fcheckbox29);
		double 	fSlow56 = double(fcheckbox30);
		double 	fSlow57 = double(fcheckbox31);
		double 	fSlow58 = double(fcheckbox32);
		double 	fSlow59 = double(fcheckbox33);
		double 	fSlow60 = double(fcheckbox34);
		int 	iSlow61 = int((fConst4 * (fSlow17 * double(fslider27))));
		double 	fSlow62 = (fConst5 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((double(fslider28) * double(fslider29)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow63 = (double(fslider30) * fSlow1);
		double 	fSlow64 = double(fcheckbox35);
		double 	fSlow65 = double(fcheckbox36);
		double 	fSlow66 = double(fcheckbox37);
		double 	fSlow67 = double(fcheckbox38);
		double 	fSlow68 = double(fcheckbox39);
		double 	fSlow69 = double(fcheckbox40);
		double 	fSlow70 = double(fcheckbox41);
		int 	iSlow71 = int((fConst4 * (fSlow17 * double(fslider31))));
		double 	fSlow72 = (fConst5 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((double(fslider32) * double(fslider33)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow73 = (double(fslider34) * fSlow1);
		double 	fSlow74 = double(fcheckbox42);
		double 	fSlow75 = double(fcheckbox43);
		double 	fSlow76 = double(fcheckbox44);
		double 	fSlow77 = double(fcheckbox45);
		double 	fSlow78 = double(fcheckbox46);
		double 	fSlow79 = double(fcheckbox47);
		double 	fSlow80 = double(fcheckbox48);
		int 	iSlow81 = int((fConst4 * (fSlow17 * double(fslider35))));
		double 	fSlow82 = (fConst5 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((double(fslider36) * double(fslider37)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow83 = (double(fslider38) * fSlow1);
		double 	fSlow84 = (double(fslider39) * fSlow1);
		double 	fSlow85 = (double(fslider40) * fSlow1);
		double 	fSlow86 = (double(fslider41) * fSlow1);
		double 	fSlow87 = (double(fslider42) * fSlow1);
		double 	fSlow88 = (double(fslider43) * fSlow1);
		double 	fSlow89 = (double(fslider44) * fSlow1);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* input2 = input[2];
		FAUSTFLOAT* input3 = input[3];
		FAUSTFLOAT* input4 = input[4];
		FAUSTFLOAT* input5 = input[5];
		FAUSTFLOAT* input6 = input[6];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		for (int i=0; i<count; i++) {
			fRec8[0] = (fConst2 + (fRec8[1] - floor((fConst2 + fRec8[1]))));
			double fTemp0 = (65536.0 * (fRec8[0] - floor(fRec8[0])));
			int iTemp1 = int(fTemp0);
			double fTemp2 = ftbl0[iTemp1];
			double fTemp3 = ((fTemp2 + ((fTemp0 - floor(fTemp0)) * (ftbl0[((iTemp1 + 1) % 65536)] - fTemp2))) + 1.0);
			fVec0[0] = fTemp3;
			fRec9[0] = (fSlow2 + (fSlow0 * fRec9[1]));
			fRec10[0] = (fSlow4 + (fSlow0 * fRec10[1]));
			double fTemp4 = (fRec10[0] * fRec0[1]);
			fRec11[0] = (fSlow6 + (fSlow0 * fRec11[1]));
			double fTemp5 = (fRec11[0] * fRec1[1]);
			fRec12[0] = (fSlow8 + (fSlow0 * fRec12[1]));
			double fTemp6 = (fRec12[0] * fRec2[1]);
			fRec13[0] = (fSlow10 + (fSlow0 * fRec13[1]));
			double fTemp7 = (fRec13[0] * fRec3[1]);
			fRec14[0] = (fSlow12 + (fSlow0 * fRec14[1]));
			double fTemp8 = (fRec14[0] * fRec4[1]);
			fRec15[0] = (fSlow14 + (fSlow0 * fRec15[1]));
			double fTemp9 = (fRec15[0] * fRec5[1]);
			fRec16[0] = (fSlow16 + (fSlow0 * fRec16[1]));
			double fTemp10 = (fRec16[0] * fRec6[1]);
			double fTemp11 = (((double)input0[i] * fRec9[0]) + (0.625 * (((((((fSlow3 * fTemp4) + (fSlow5 * fTemp5)) + (fSlow7 * fTemp6)) + (fSlow9 * fTemp7)) + (fSlow11 * fTemp8)) + (fSlow13 * fTemp9)) + (fSlow15 * fTemp10))));
			fVec1[IOTA&1048575] = fTemp11;
			double fTemp12 = (0.5 * fVec0[0]);
			int iTemp13 = ((fTemp12 > 0.001) * ((0.5 * fVec0[1]) <= 0.001));
			int iTemp14 = (1 - iTemp13);
			iRec17[0] = ((iRec17[1] * iTemp14) + (iSlow18 * iTemp13));
			double fTemp15 = (1 - fTemp12);
			fVec2[0] = fTemp15;
			int iTemp16 = ((fVec2[0] > 0.001) * (fVec2[1] <= 0.001));
			int iTemp17 = (1 - iTemp16);
			iRec18[0] = ((iRec18[1] * iTemp17) + (iSlow18 * iTemp16));
			double fTemp18 = ((0.5 * (fVec0[0] * fVec1[(IOTA-int((int(iRec17[0]) & 1048575)))&1048575])) + (fVec2[0] * fVec1[(IOTA-int((int(iRec18[0]) & 1048575)))&1048575]));
			int iTemp19 = (fTemp18 > 1);
			int iTemp20 = (fTemp18 < -1);
			double fTemp21 = ((iTemp19 + ((fTemp18 * (1 - iTemp20)) * (1 - iTemp19))) - iTemp20);
			fVec3[IOTA&262143] = fTemp21;
			fVec4[0] = fSlow22;
			double fTemp22 = ((int((fSlow22 != fVec4[1])))?fConst6:(fRec21[1] + -1));
			fRec21[0] = fTemp22;
			fRec22[0] = ((int((fTemp22 <= 0)))?fSlow22:(fRec22[1] + ((fSlow22 - fRec22[1]) / fTemp22)));
			double fTemp23 = double(fRec22[0]);
			double fTemp24 = (fRec20[1] + (fSlow19 / fTemp23));
			fRec20[0] = (fTemp24 - floor(fTemp24));
			double fTemp25 = (fRec20[0] - floor(fRec20[0]));
			fVec5[0] = fTemp25;
			int iTemp26 = (fVec5[0] > 0.001);
			int iTemp27 = (fVec5[1] <= 0.001);
			fRec19[0] = ((fRec19[1] * (1 - (iTemp26 * iTemp27))) + ((fRec22[0] * iTemp26) * iTemp27));
			double fTemp28 = (fConst4 * (fRec19[0] * fVec5[0]));
			int iTemp29 = int(fTemp28);
			double fTemp30 = floor(fTemp28);
			double fTemp31 = (0.5 * fVec5[0]);
			double fTemp32 = (65536.0 * (fTemp31 - floor(fTemp31)));
			int iTemp33 = int(fTemp32);
			double fTemp34 = ftbl0[iTemp33];
			double fTemp35 = (fRec20[0] + (0.25 - floor((fRec20[0] + 0.25))));
			fVec6[0] = fTemp35;
			int iTemp36 = (fVec6[0] > 0.001);
			int iTemp37 = (fVec6[1] <= 0.001);
			fRec23[0] = ((fRec23[1] * (1 - (iTemp36 * iTemp37))) + ((fRec22[0] * iTemp36) * iTemp37));
			double fTemp38 = (fConst4 * (fRec23[0] * fVec6[0]));
			int iTemp39 = int(fTemp38);
			double fTemp40 = floor(fTemp38);
			double fTemp41 = (0.5 * fVec6[0]);
			double fTemp42 = (65536.0 * (fTemp41 - floor(fTemp41)));
			int iTemp43 = int(fTemp42);
			double fTemp44 = ftbl0[iTemp43];
			double fTemp45 = (fRec20[0] + (0.5 - floor((fRec20[0] + 0.5))));
			fVec7[0] = fTemp45;
			int iTemp46 = (fVec7[0] > 0.001);
			int iTemp47 = (fVec7[1] <= 0.001);
			fRec24[0] = ((fRec24[1] * (1 - (iTemp46 * iTemp47))) + ((fRec22[0] * iTemp46) * iTemp47));
			double fTemp48 = (fConst4 * (fRec24[0] * fVec7[0]));
			int iTemp49 = int(fTemp48);
			double fTemp50 = floor(fTemp48);
			double fTemp51 = (0.5 * fVec7[0]);
			double fTemp52 = (65536.0 * (fTemp51 - floor(fTemp51)));
			int iTemp53 = int(fTemp52);
			double fTemp54 = ftbl0[iTemp53];
			double fTemp55 = (fRec20[0] + (0.75 - floor((fRec20[0] + 0.75))));
			fVec8[0] = fTemp55;
			int iTemp56 = (fVec8[0] > 0.001);
			int iTemp57 = (fVec8[1] <= 0.001);
			fRec25[0] = ((fRec25[1] * (1 - (iTemp56 * iTemp57))) + ((fRec22[0] * iTemp56) * iTemp57));
			double fTemp58 = (fConst4 * (fRec25[0] * fVec8[0]));
			int iTemp59 = int(fTemp58);
			double fTemp60 = floor(fTemp58);
			double fTemp61 = (0.5 * fVec8[0]);
			double fTemp62 = (65536.0 * (fTemp61 - floor(fTemp61)));
			int iTemp63 = int(fTemp62);
			double fTemp64 = ftbl0[iTemp63];
			fRec0[0] = ((0.5 * fVec3[IOTA&262143]) + (0.25 * ((((((fVec3[(IOTA-int((iTemp29 & 262143)))&262143] * (fTemp30 + (1 - fTemp28))) + ((fTemp28 - fTemp30) * fVec3[(IOTA-int((int((iTemp29 + 1)) & 262143)))&262143])) * (fTemp34 + ((fTemp32 - floor(fTemp32)) * (ftbl0[((iTemp33 + 1) % 65536)] - fTemp34)))) + (((fVec3[(IOTA-int((iTemp39 & 262143)))&262143] * (fTemp40 + (1 - fTemp38))) + ((fTemp38 - fTemp40) * fVec3[(IOTA-int((int((iTemp39 + 1)) & 262143)))&262143])) * (fTemp44 + ((fTemp42 - floor(fTemp42)) * (ftbl0[((iTemp43 + 1) % 65536)] - fTemp44))))) + (((fVec3[(IOTA-int((iTemp49 & 262143)))&262143] * (fTemp50 + (1 - fTemp48))) + ((fTemp48 - fTemp50) * fVec3[(IOTA-int((int((iTemp49 + 1)) & 262143)))&262143])) * (fTemp54 + ((fTemp52 - floor(fTemp52)) * (ftbl0[((iTemp53 + 1) % 65536)] - fTemp54))))) + (((fVec3[(IOTA-int((iTemp59 & 262143)))&262143] * (fTemp60 + (1 - fTemp58))) + ((fTemp58 - fTemp60) * fVec3[(IOTA-int((int((iTemp59 + 1)) & 262143)))&262143])) * (fTemp64 + ((fTemp62 - floor(fTemp62)) * (ftbl0[((iTemp63 + 1) % 65536)] - fTemp64)))))));
			fRec26[0] = (fSlow23 + (fSlow0 * fRec26[1]));
			double fTemp65 = (((double)input1[i] * fRec26[0]) + (0.625 * (((((((fSlow24 * fTemp4) + (fSlow25 * fTemp5)) + (fSlow26 * fTemp6)) + (fSlow27 * fTemp7)) + (fSlow28 * fTemp8)) + (fSlow29 * fTemp9)) + (fSlow30 * fTemp10))));
			fVec9[IOTA&1048575] = fTemp65;
			iRec27[0] = ((iTemp14 * iRec27[1]) + (iSlow31 * iTemp13));
			iRec28[0] = ((iTemp17 * iRec28[1]) + (iSlow31 * iTemp16));
			double fTemp66 = ((0.5 * (fVec0[0] * fVec9[(IOTA-int((int(iRec27[0]) & 1048575)))&1048575])) + (fVec2[0] * fVec9[(IOTA-int((int(iRec28[0]) & 1048575)))&1048575]));
			int iTemp67 = (fTemp66 > 1);
			int iTemp68 = (fTemp66 < -1);
			double fTemp69 = ((iTemp67 + ((fTemp66 * (1 - iTemp68)) * (1 - iTemp67))) - iTemp68);
			fVec10[IOTA&262143] = fTemp69;
			double fTemp70 = (fRec30[1] + (fSlow32 / fTemp23));
			fRec30[0] = (fTemp70 - floor(fTemp70));
			double fTemp71 = (fRec30[0] - floor(fRec30[0]));
			fVec11[0] = fTemp71;
			int iTemp72 = (fVec11[0] > 0.001);
			int iTemp73 = (fVec11[1] <= 0.001);
			fRec29[0] = ((fRec29[1] * (1 - (iTemp72 * iTemp73))) + ((fRec22[0] * iTemp72) * iTemp73));
			double fTemp74 = (fConst4 * (fRec29[0] * fVec11[0]));
			int iTemp75 = int(fTemp74);
			double fTemp76 = floor(fTemp74);
			double fTemp77 = (0.5 * fVec11[0]);
			double fTemp78 = (65536.0 * (fTemp77 - floor(fTemp77)));
			int iTemp79 = int(fTemp78);
			double fTemp80 = ftbl0[iTemp79];
			double fTemp81 = (fRec30[0] + (0.25 - floor((fRec30[0] + 0.25))));
			fVec12[0] = fTemp81;
			int iTemp82 = (fVec12[0] > 0.001);
			int iTemp83 = (fVec12[1] <= 0.001);
			fRec31[0] = ((fRec31[1] * (1 - (iTemp82 * iTemp83))) + ((fRec22[0] * iTemp82) * iTemp83));
			double fTemp84 = (fConst4 * (fRec31[0] * fVec12[0]));
			int iTemp85 = int(fTemp84);
			double fTemp86 = floor(fTemp84);
			double fTemp87 = (0.5 * fVec12[0]);
			double fTemp88 = (65536.0 * (fTemp87 - floor(fTemp87)));
			int iTemp89 = int(fTemp88);
			double fTemp90 = ftbl0[iTemp89];
			double fTemp91 = (fRec30[0] + (0.5 - floor((fRec30[0] + 0.5))));
			fVec13[0] = fTemp91;
			int iTemp92 = (fVec13[0] > 0.001);
			int iTemp93 = (fVec13[1] <= 0.001);
			fRec32[0] = ((fRec32[1] * (1 - (iTemp92 * iTemp93))) + ((fRec22[0] * iTemp92) * iTemp93));
			double fTemp94 = (fConst4 * (fRec32[0] * fVec13[0]));
			int iTemp95 = int(fTemp94);
			double fTemp96 = floor(fTemp94);
			double fTemp97 = (0.5 * fVec13[0]);
			double fTemp98 = (65536.0 * (fTemp97 - floor(fTemp97)));
			int iTemp99 = int(fTemp98);
			double fTemp100 = ftbl0[iTemp99];
			double fTemp101 = (fRec30[0] + (0.75 - floor((fRec30[0] + 0.75))));
			fVec14[0] = fTemp101;
			int iTemp102 = (fVec14[0] > 0.001);
			int iTemp103 = (fVec14[1] <= 0.001);
			fRec33[0] = ((fRec33[1] * (1 - (iTemp102 * iTemp103))) + ((fRec22[0] * iTemp102) * iTemp103));
			double fTemp104 = (fConst4 * (fRec33[0] * fVec14[0]));
			int iTemp105 = int(fTemp104);
			double fTemp106 = floor(fTemp104);
			double fTemp107 = (0.5 * fVec14[0]);
			double fTemp108 = (65536.0 * (fTemp107 - floor(fTemp107)));
			int iTemp109 = int(fTemp108);
			double fTemp110 = ftbl0[iTemp109];
			fRec1[0] = ((0.5 * fVec10[IOTA&262143]) + (0.25 * ((((((fVec10[(IOTA-int((iTemp75 & 262143)))&262143] * (fTemp76 + (1 - fTemp74))) + ((fTemp74 - fTemp76) * fVec10[(IOTA-int((int((iTemp75 + 1)) & 262143)))&262143])) * (fTemp80 + ((fTemp78 - floor(fTemp78)) * (ftbl0[((iTemp79 + 1) % 65536)] - fTemp80)))) + (((fVec10[(IOTA-int((iTemp85 & 262143)))&262143] * (fTemp86 + (1 - fTemp84))) + ((fTemp84 - fTemp86) * fVec10[(IOTA-int((int((iTemp85 + 1)) & 262143)))&262143])) * (fTemp90 + ((fTemp88 - floor(fTemp88)) * (ftbl0[((iTemp89 + 1) % 65536)] - fTemp90))))) + (((fVec10[(IOTA-int((iTemp95 & 262143)))&262143] * (fTemp96 + (1 - fTemp94))) + ((fTemp94 - fTemp96) * fVec10[(IOTA-int((int((iTemp95 + 1)) & 262143)))&262143])) * (fTemp100 + ((fTemp98 - floor(fTemp98)) * (ftbl0[((iTemp99 + 1) % 65536)] - fTemp100))))) + (((fVec10[(IOTA-int((iTemp105 & 262143)))&262143] * (fTemp106 + (1 - fTemp104))) + ((fTemp104 - fTemp106) * fVec10[(IOTA-int((int((iTemp105 + 1)) & 262143)))&262143])) * (fTemp110 + ((fTemp108 - floor(fTemp108)) * (ftbl0[((iTemp109 + 1) % 65536)] - fTemp110)))))));
			fRec34[0] = (fSlow33 + (fSlow0 * fRec34[1]));
			double fTemp111 = (((double)input2[i] * fRec34[0]) + (0.625 * (((((((fSlow34 * fTemp4) + (fSlow35 * fTemp5)) + (fSlow36 * fTemp6)) + (fSlow37 * fTemp7)) + (fSlow38 * fTemp8)) + (fSlow39 * fTemp9)) + (fSlow40 * fTemp10))));
			fVec15[IOTA&1048575] = fTemp111;
			iRec35[0] = ((iTemp14 * iRec35[1]) + (iSlow41 * iTemp13));
			iRec36[0] = ((iTemp17 * iRec36[1]) + (iSlow41 * iTemp16));
			double fTemp112 = ((0.5 * (fVec0[0] * fVec15[(IOTA-int((int(iRec35[0]) & 1048575)))&1048575])) + (fVec2[0] * fVec15[(IOTA-int((int(iRec36[0]) & 1048575)))&1048575]));
			int iTemp113 = (fTemp112 > 1);
			int iTemp114 = (fTemp112 < -1);
			double fTemp115 = ((iTemp113 + ((fTemp112 * (1 - iTemp114)) * (1 - iTemp113))) - iTemp114);
			fVec16[IOTA&262143] = fTemp115;
			double fTemp116 = (fRec38[1] + (fSlow42 / fTemp23));
			fRec38[0] = (fTemp116 - floor(fTemp116));
			double fTemp117 = (fRec38[0] - floor(fRec38[0]));
			fVec17[0] = fTemp117;
			int iTemp118 = (fVec17[0] > 0.001);
			int iTemp119 = (fVec17[1] <= 0.001);
			fRec37[0] = ((fRec37[1] * (1 - (iTemp118 * iTemp119))) + ((fRec22[0] * iTemp118) * iTemp119));
			double fTemp120 = (fConst4 * (fRec37[0] * fVec17[0]));
			int iTemp121 = int(fTemp120);
			double fTemp122 = floor(fTemp120);
			double fTemp123 = (0.5 * fVec17[0]);
			double fTemp124 = (65536.0 * (fTemp123 - floor(fTemp123)));
			int iTemp125 = int(fTemp124);
			double fTemp126 = ftbl0[iTemp125];
			double fTemp127 = (fRec38[0] + (0.25 - floor((fRec38[0] + 0.25))));
			fVec18[0] = fTemp127;
			int iTemp128 = (fVec18[0] > 0.001);
			int iTemp129 = (fVec18[1] <= 0.001);
			fRec39[0] = ((fRec39[1] * (1 - (iTemp128 * iTemp129))) + ((fRec22[0] * iTemp128) * iTemp129));
			double fTemp130 = (fConst4 * (fRec39[0] * fVec18[0]));
			int iTemp131 = int(fTemp130);
			double fTemp132 = floor(fTemp130);
			double fTemp133 = (0.5 * fVec18[0]);
			double fTemp134 = (65536.0 * (fTemp133 - floor(fTemp133)));
			int iTemp135 = int(fTemp134);
			double fTemp136 = ftbl0[iTemp135];
			double fTemp137 = (fRec38[0] + (0.5 - floor((fRec38[0] + 0.5))));
			fVec19[0] = fTemp137;
			int iTemp138 = (fVec19[0] > 0.001);
			int iTemp139 = (fVec19[1] <= 0.001);
			fRec40[0] = ((fRec40[1] * (1 - (iTemp138 * iTemp139))) + ((fRec22[0] * iTemp138) * iTemp139));
			double fTemp140 = (fConst4 * (fRec40[0] * fVec19[0]));
			int iTemp141 = int(fTemp140);
			double fTemp142 = floor(fTemp140);
			double fTemp143 = (0.5 * fVec19[0]);
			double fTemp144 = (65536.0 * (fTemp143 - floor(fTemp143)));
			int iTemp145 = int(fTemp144);
			double fTemp146 = ftbl0[iTemp145];
			double fTemp147 = (fRec38[0] + (0.75 - floor((fRec38[0] + 0.75))));
			fVec20[0] = fTemp147;
			int iTemp148 = (fVec20[0] > 0.001);
			int iTemp149 = (fVec20[1] <= 0.001);
			fRec41[0] = ((fRec41[1] * (1 - (iTemp148 * iTemp149))) + ((fRec22[0] * iTemp148) * iTemp149));
			double fTemp150 = (fConst4 * (fRec41[0] * fVec20[0]));
			int iTemp151 = int(fTemp150);
			double fTemp152 = floor(fTemp150);
			double fTemp153 = (0.5 * fVec20[0]);
			double fTemp154 = (65536.0 * (fTemp153 - floor(fTemp153)));
			int iTemp155 = int(fTemp154);
			double fTemp156 = ftbl0[iTemp155];
			fRec2[0] = ((0.5 * fVec16[IOTA&262143]) + (0.25 * ((((((fVec16[(IOTA-int((iTemp121 & 262143)))&262143] * (fTemp122 + (1 - fTemp120))) + ((fTemp120 - fTemp122) * fVec16[(IOTA-int((int((iTemp121 + 1)) & 262143)))&262143])) * (fTemp126 + ((fTemp124 - floor(fTemp124)) * (ftbl0[((iTemp125 + 1) % 65536)] - fTemp126)))) + (((fVec16[(IOTA-int((iTemp131 & 262143)))&262143] * (fTemp132 + (1 - fTemp130))) + ((fTemp130 - fTemp132) * fVec16[(IOTA-int((int((iTemp131 + 1)) & 262143)))&262143])) * (fTemp136 + ((fTemp134 - floor(fTemp134)) * (ftbl0[((iTemp135 + 1) % 65536)] - fTemp136))))) + (((fVec16[(IOTA-int((iTemp141 & 262143)))&262143] * (fTemp142 + (1 - fTemp140))) + ((fTemp140 - fTemp142) * fVec16[(IOTA-int((int((iTemp141 + 1)) & 262143)))&262143])) * (fTemp146 + ((fTemp144 - floor(fTemp144)) * (ftbl0[((iTemp145 + 1) % 65536)] - fTemp146))))) + (((fVec16[(IOTA-int((iTemp151 & 262143)))&262143] * (fTemp152 + (1 - fTemp150))) + ((fTemp150 - fTemp152) * fVec16[(IOTA-int((int((iTemp151 + 1)) & 262143)))&262143])) * (fTemp156 + ((fTemp154 - floor(fTemp154)) * (ftbl0[((iTemp155 + 1) % 65536)] - fTemp156)))))));
			fRec42[0] = (fSlow43 + (fSlow0 * fRec42[1]));
			double fTemp157 = (((double)input3[i] * fRec42[0]) + (0.625 * (((((((fSlow44 * fTemp4) + (fSlow45 * fTemp5)) + (fSlow46 * fTemp6)) + (fSlow47 * fTemp7)) + (fSlow48 * fTemp8)) + (fSlow49 * fTemp9)) + (fSlow50 * fTemp10))));
			fVec21[IOTA&1048575] = fTemp157;
			iRec43[0] = ((iTemp14 * iRec43[1]) + (iSlow51 * iTemp13));
			iRec44[0] = ((iTemp17 * iRec44[1]) + (iSlow51 * iTemp16));
			double fTemp158 = ((0.5 * (fVec0[0] * fVec21[(IOTA-int((int(iRec43[0]) & 1048575)))&1048575])) + (fVec2[0] * fVec21[(IOTA-int((int(iRec44[0]) & 1048575)))&1048575]));
			int iTemp159 = (fTemp158 > 1);
			int iTemp160 = (fTemp158 < -1);
			double fTemp161 = ((iTemp159 + ((fTemp158 * (1 - iTemp160)) * (1 - iTemp159))) - iTemp160);
			fVec22[IOTA&262143] = fTemp161;
			double fTemp162 = (fRec46[1] + (fSlow52 / fTemp23));
			fRec46[0] = (fTemp162 - floor(fTemp162));
			double fTemp163 = (fRec46[0] - floor(fRec46[0]));
			fVec23[0] = fTemp163;
			int iTemp164 = (fVec23[0] > 0.001);
			int iTemp165 = (fVec23[1] <= 0.001);
			fRec45[0] = ((fRec45[1] * (1 - (iTemp164 * iTemp165))) + ((fRec22[0] * iTemp164) * iTemp165));
			double fTemp166 = (fConst4 * (fRec45[0] * fVec23[0]));
			int iTemp167 = int(fTemp166);
			double fTemp168 = floor(fTemp166);
			double fTemp169 = (0.5 * fVec23[0]);
			double fTemp170 = (65536.0 * (fTemp169 - floor(fTemp169)));
			int iTemp171 = int(fTemp170);
			double fTemp172 = ftbl0[iTemp171];
			double fTemp173 = (fRec46[0] + (0.25 - floor((fRec46[0] + 0.25))));
			fVec24[0] = fTemp173;
			int iTemp174 = (fVec24[0] > 0.001);
			int iTemp175 = (fVec24[1] <= 0.001);
			fRec47[0] = ((fRec47[1] * (1 - (iTemp174 * iTemp175))) + ((fRec22[0] * iTemp174) * iTemp175));
			double fTemp176 = (fConst4 * (fRec47[0] * fVec24[0]));
			int iTemp177 = int(fTemp176);
			double fTemp178 = floor(fTemp176);
			double fTemp179 = (0.5 * fVec24[0]);
			double fTemp180 = (65536.0 * (fTemp179 - floor(fTemp179)));
			int iTemp181 = int(fTemp180);
			double fTemp182 = ftbl0[iTemp181];
			double fTemp183 = (fRec46[0] + (0.5 - floor((fRec46[0] + 0.5))));
			fVec25[0] = fTemp183;
			int iTemp184 = (fVec25[0] > 0.001);
			int iTemp185 = (fVec25[1] <= 0.001);
			fRec48[0] = ((fRec48[1] * (1 - (iTemp184 * iTemp185))) + ((fRec22[0] * iTemp184) * iTemp185));
			double fTemp186 = (fConst4 * (fRec48[0] * fVec25[0]));
			int iTemp187 = int(fTemp186);
			double fTemp188 = floor(fTemp186);
			double fTemp189 = (0.5 * fVec25[0]);
			double fTemp190 = (65536.0 * (fTemp189 - floor(fTemp189)));
			int iTemp191 = int(fTemp190);
			double fTemp192 = ftbl0[iTemp191];
			double fTemp193 = (fRec46[0] + (0.75 - floor((fRec46[0] + 0.75))));
			fVec26[0] = fTemp193;
			int iTemp194 = (fVec26[0] > 0.001);
			int iTemp195 = (fVec26[1] <= 0.001);
			fRec49[0] = ((fRec49[1] * (1 - (iTemp194 * iTemp195))) + ((fRec22[0] * iTemp194) * iTemp195));
			double fTemp196 = (fConst4 * (fRec49[0] * fVec26[0]));
			int iTemp197 = int(fTemp196);
			double fTemp198 = floor(fTemp196);
			double fTemp199 = (0.5 * fVec26[0]);
			double fTemp200 = (65536.0 * (fTemp199 - floor(fTemp199)));
			int iTemp201 = int(fTemp200);
			double fTemp202 = ftbl0[iTemp201];
			fRec3[0] = ((0.5 * fVec22[IOTA&262143]) + (0.25 * ((((((fVec22[(IOTA-int((iTemp167 & 262143)))&262143] * (fTemp168 + (1 - fTemp166))) + ((fTemp166 - fTemp168) * fVec22[(IOTA-int((int((iTemp167 + 1)) & 262143)))&262143])) * (fTemp172 + ((fTemp170 - floor(fTemp170)) * (ftbl0[((iTemp171 + 1) % 65536)] - fTemp172)))) + (((fVec22[(IOTA-int((iTemp177 & 262143)))&262143] * (fTemp178 + (1 - fTemp176))) + ((fTemp176 - fTemp178) * fVec22[(IOTA-int((int((iTemp177 + 1)) & 262143)))&262143])) * (fTemp182 + ((fTemp180 - floor(fTemp180)) * (ftbl0[((iTemp181 + 1) % 65536)] - fTemp182))))) + (((fVec22[(IOTA-int((iTemp187 & 262143)))&262143] * (fTemp188 + (1 - fTemp186))) + ((fTemp186 - fTemp188) * fVec22[(IOTA-int((int((iTemp187 + 1)) & 262143)))&262143])) * (fTemp192 + ((fTemp190 - floor(fTemp190)) * (ftbl0[((iTemp191 + 1) % 65536)] - fTemp192))))) + (((fVec22[(IOTA-int((iTemp197 & 262143)))&262143] * (fTemp198 + (1 - fTemp196))) + ((fTemp196 - fTemp198) * fVec22[(IOTA-int((int((iTemp197 + 1)) & 262143)))&262143])) * (fTemp202 + ((fTemp200 - floor(fTemp200)) * (ftbl0[((iTemp201 + 1) % 65536)] - fTemp202)))))));
			fRec50[0] = (fSlow53 + (fSlow0 * fRec50[1]));
			double fTemp203 = (((double)input4[i] * fRec50[0]) + (0.625 * (((((((fSlow54 * fTemp4) + (fSlow55 * fTemp5)) + (fSlow56 * fTemp6)) + (fSlow57 * fTemp7)) + (fSlow58 * fTemp8)) + (fSlow59 * fTemp9)) + (fSlow60 * fTemp10))));
			fVec27[IOTA&1048575] = fTemp203;
			iRec51[0] = ((iTemp14 * iRec51[1]) + (iSlow61 * iTemp13));
			iRec52[0] = ((iTemp17 * iRec52[1]) + (iSlow61 * iTemp16));
			double fTemp204 = ((0.5 * (fVec0[0] * fVec27[(IOTA-int((int(iRec51[0]) & 1048575)))&1048575])) + (fVec2[0] * fVec27[(IOTA-int((int(iRec52[0]) & 1048575)))&1048575]));
			int iTemp205 = (fTemp204 > 1);
			int iTemp206 = (fTemp204 < -1);
			double fTemp207 = ((iTemp205 + ((fTemp204 * (1 - iTemp206)) * (1 - iTemp205))) - iTemp206);
			fVec28[IOTA&262143] = fTemp207;
			double fTemp208 = (fRec54[1] + (fSlow62 / fTemp23));
			fRec54[0] = (fTemp208 - floor(fTemp208));
			double fTemp209 = (fRec54[0] - floor(fRec54[0]));
			fVec29[0] = fTemp209;
			int iTemp210 = (fVec29[0] > 0.001);
			int iTemp211 = (fVec29[1] <= 0.001);
			fRec53[0] = ((fRec53[1] * (1 - (iTemp210 * iTemp211))) + ((fRec22[0] * iTemp210) * iTemp211));
			double fTemp212 = (fConst4 * (fRec53[0] * fVec29[0]));
			int iTemp213 = int(fTemp212);
			double fTemp214 = floor(fTemp212);
			double fTemp215 = (0.5 * fVec29[0]);
			double fTemp216 = (65536.0 * (fTemp215 - floor(fTemp215)));
			int iTemp217 = int(fTemp216);
			double fTemp218 = ftbl0[iTemp217];
			double fTemp219 = (fRec54[0] + (0.25 - floor((fRec54[0] + 0.25))));
			fVec30[0] = fTemp219;
			int iTemp220 = (fVec30[0] > 0.001);
			int iTemp221 = (fVec30[1] <= 0.001);
			fRec55[0] = ((fRec55[1] * (1 - (iTemp220 * iTemp221))) + ((fRec22[0] * iTemp220) * iTemp221));
			double fTemp222 = (fConst4 * (fRec55[0] * fVec30[0]));
			int iTemp223 = int(fTemp222);
			double fTemp224 = floor(fTemp222);
			double fTemp225 = (0.5 * fVec30[0]);
			double fTemp226 = (65536.0 * (fTemp225 - floor(fTemp225)));
			int iTemp227 = int(fTemp226);
			double fTemp228 = ftbl0[iTemp227];
			double fTemp229 = (fRec54[0] + (0.5 - floor((fRec54[0] + 0.5))));
			fVec31[0] = fTemp229;
			int iTemp230 = (fVec31[0] > 0.001);
			int iTemp231 = (fVec31[1] <= 0.001);
			fRec56[0] = ((fRec56[1] * (1 - (iTemp230 * iTemp231))) + ((fRec22[0] * iTemp230) * iTemp231));
			double fTemp232 = (fConst4 * (fRec56[0] * fVec31[0]));
			int iTemp233 = int(fTemp232);
			double fTemp234 = floor(fTemp232);
			double fTemp235 = (0.5 * fVec31[0]);
			double fTemp236 = (65536.0 * (fTemp235 - floor(fTemp235)));
			int iTemp237 = int(fTemp236);
			double fTemp238 = ftbl0[iTemp237];
			double fTemp239 = (fRec54[0] + (0.75 - floor((fRec54[0] + 0.75))));
			fVec32[0] = fTemp239;
			int iTemp240 = (fVec32[0] > 0.001);
			int iTemp241 = (fVec32[1] <= 0.001);
			fRec57[0] = ((fRec57[1] * (1 - (iTemp240 * iTemp241))) + ((fRec22[0] * iTemp240) * iTemp241));
			double fTemp242 = (fConst4 * (fRec57[0] * fVec32[0]));
			int iTemp243 = int(fTemp242);
			double fTemp244 = floor(fTemp242);
			double fTemp245 = (0.5 * fVec32[0]);
			double fTemp246 = (65536.0 * (fTemp245 - floor(fTemp245)));
			int iTemp247 = int(fTemp246);
			double fTemp248 = ftbl0[iTemp247];
			fRec4[0] = ((0.5 * fVec28[IOTA&262143]) + (0.25 * ((((((fVec28[(IOTA-int((iTemp213 & 262143)))&262143] * (fTemp214 + (1 - fTemp212))) + ((fTemp212 - fTemp214) * fVec28[(IOTA-int((int((iTemp213 + 1)) & 262143)))&262143])) * (fTemp218 + ((fTemp216 - floor(fTemp216)) * (ftbl0[((iTemp217 + 1) % 65536)] - fTemp218)))) + (((fVec28[(IOTA-int((iTemp223 & 262143)))&262143] * (fTemp224 + (1 - fTemp222))) + ((fTemp222 - fTemp224) * fVec28[(IOTA-int((int((iTemp223 + 1)) & 262143)))&262143])) * (fTemp228 + ((fTemp226 - floor(fTemp226)) * (ftbl0[((iTemp227 + 1) % 65536)] - fTemp228))))) + (((fVec28[(IOTA-int((iTemp233 & 262143)))&262143] * (fTemp234 + (1 - fTemp232))) + ((fTemp232 - fTemp234) * fVec28[(IOTA-int((int((iTemp233 + 1)) & 262143)))&262143])) * (fTemp238 + ((fTemp236 - floor(fTemp236)) * (ftbl0[((iTemp237 + 1) % 65536)] - fTemp238))))) + (((fVec28[(IOTA-int((iTemp243 & 262143)))&262143] * (fTemp244 + (1 - fTemp242))) + ((fTemp242 - fTemp244) * fVec28[(IOTA-int((int((iTemp243 + 1)) & 262143)))&262143])) * (fTemp248 + ((fTemp246 - floor(fTemp246)) * (ftbl0[((iTemp247 + 1) % 65536)] - fTemp248)))))));
			fRec58[0] = (fSlow63 + (fSlow0 * fRec58[1]));
			double fTemp249 = (((double)input5[i] * fRec58[0]) + (0.625 * (((((((fSlow64 * fTemp4) + (fSlow65 * fTemp5)) + (fSlow66 * fTemp6)) + (fSlow67 * fTemp7)) + (fSlow68 * fTemp8)) + (fSlow69 * fTemp9)) + (fSlow70 * fTemp10))));
			fVec33[IOTA&1048575] = fTemp249;
			iRec59[0] = ((iTemp14 * iRec59[1]) + (iSlow71 * iTemp13));
			iRec60[0] = ((iTemp17 * iRec60[1]) + (iSlow71 * iTemp16));
			double fTemp250 = ((0.5 * (fVec0[0] * fVec33[(IOTA-int((int(iRec59[0]) & 1048575)))&1048575])) + (fVec2[0] * fVec33[(IOTA-int((int(iRec60[0]) & 1048575)))&1048575]));
			int iTemp251 = (fTemp250 > 1);
			int iTemp252 = (fTemp250 < -1);
			double fTemp253 = ((iTemp251 + ((fTemp250 * (1 - iTemp252)) * (1 - iTemp251))) - iTemp252);
			fVec34[IOTA&262143] = fTemp253;
			double fTemp254 = (fRec62[1] + (fSlow72 / fTemp23));
			fRec62[0] = (fTemp254 - floor(fTemp254));
			double fTemp255 = (fRec62[0] - floor(fRec62[0]));
			fVec35[0] = fTemp255;
			int iTemp256 = (fVec35[0] > 0.001);
			int iTemp257 = (fVec35[1] <= 0.001);
			fRec61[0] = ((fRec61[1] * (1 - (iTemp256 * iTemp257))) + ((fRec22[0] * iTemp256) * iTemp257));
			double fTemp258 = (fConst4 * (fRec61[0] * fVec35[0]));
			int iTemp259 = int(fTemp258);
			double fTemp260 = floor(fTemp258);
			double fTemp261 = (0.5 * fVec35[0]);
			double fTemp262 = (65536.0 * (fTemp261 - floor(fTemp261)));
			int iTemp263 = int(fTemp262);
			double fTemp264 = ftbl0[iTemp263];
			double fTemp265 = (fRec62[0] + (0.25 - floor((fRec62[0] + 0.25))));
			fVec36[0] = fTemp265;
			int iTemp266 = (fVec36[0] > 0.001);
			int iTemp267 = (fVec36[1] <= 0.001);
			fRec63[0] = ((fRec63[1] * (1 - (iTemp266 * iTemp267))) + ((fRec22[0] * iTemp266) * iTemp267));
			double fTemp268 = (fConst4 * (fRec63[0] * fVec36[0]));
			int iTemp269 = int(fTemp268);
			double fTemp270 = floor(fTemp268);
			double fTemp271 = (0.5 * fVec36[0]);
			double fTemp272 = (65536.0 * (fTemp271 - floor(fTemp271)));
			int iTemp273 = int(fTemp272);
			double fTemp274 = ftbl0[iTemp273];
			double fTemp275 = (fRec62[0] + (0.5 - floor((fRec62[0] + 0.5))));
			fVec37[0] = fTemp275;
			int iTemp276 = (fVec37[0] > 0.001);
			int iTemp277 = (fVec37[1] <= 0.001);
			fRec64[0] = ((fRec64[1] * (1 - (iTemp276 * iTemp277))) + ((fRec22[0] * iTemp276) * iTemp277));
			double fTemp278 = (fConst4 * (fRec64[0] * fVec37[0]));
			int iTemp279 = int(fTemp278);
			double fTemp280 = floor(fTemp278);
			double fTemp281 = (0.5 * fVec37[0]);
			double fTemp282 = (65536.0 * (fTemp281 - floor(fTemp281)));
			int iTemp283 = int(fTemp282);
			double fTemp284 = ftbl0[iTemp283];
			double fTemp285 = (fRec62[0] + (0.75 - floor((fRec62[0] + 0.75))));
			fVec38[0] = fTemp285;
			int iTemp286 = (fVec38[0] > 0.001);
			int iTemp287 = (fVec38[1] <= 0.001);
			fRec65[0] = ((fRec65[1] * (1 - (iTemp286 * iTemp287))) + ((fRec22[0] * iTemp286) * iTemp287));
			double fTemp288 = (fConst4 * (fRec65[0] * fVec38[0]));
			int iTemp289 = int(fTemp288);
			double fTemp290 = floor(fTemp288);
			double fTemp291 = (0.5 * fVec38[0]);
			double fTemp292 = (65536.0 * (fTemp291 - floor(fTemp291)));
			int iTemp293 = int(fTemp292);
			double fTemp294 = ftbl0[iTemp293];
			fRec5[0] = ((0.5 * fVec34[IOTA&262143]) + (0.25 * ((((((fVec34[(IOTA-int((iTemp259 & 262143)))&262143] * (fTemp260 + (1 - fTemp258))) + ((fTemp258 - fTemp260) * fVec34[(IOTA-int((int((iTemp259 + 1)) & 262143)))&262143])) * (fTemp264 + ((fTemp262 - floor(fTemp262)) * (ftbl0[((iTemp263 + 1) % 65536)] - fTemp264)))) + (((fVec34[(IOTA-int((iTemp269 & 262143)))&262143] * (fTemp270 + (1 - fTemp268))) + ((fTemp268 - fTemp270) * fVec34[(IOTA-int((int((iTemp269 + 1)) & 262143)))&262143])) * (fTemp274 + ((fTemp272 - floor(fTemp272)) * (ftbl0[((iTemp273 + 1) % 65536)] - fTemp274))))) + (((fVec34[(IOTA-int((iTemp279 & 262143)))&262143] * (fTemp280 + (1 - fTemp278))) + ((fTemp278 - fTemp280) * fVec34[(IOTA-int((int((iTemp279 + 1)) & 262143)))&262143])) * (fTemp284 + ((fTemp282 - floor(fTemp282)) * (ftbl0[((iTemp283 + 1) % 65536)] - fTemp284))))) + (((fVec34[(IOTA-int((iTemp289 & 262143)))&262143] * (fTemp290 + (1 - fTemp288))) + ((fTemp288 - fTemp290) * fVec34[(IOTA-int((int((iTemp289 + 1)) & 262143)))&262143])) * (fTemp294 + ((fTemp292 - floor(fTemp292)) * (ftbl0[((iTemp293 + 1) % 65536)] - fTemp294)))))));
			fRec66[0] = (fSlow73 + (fSlow0 * fRec66[1]));
			double fTemp295 = (((double)input6[i] * fRec66[0]) + (0.625 * (((((((fSlow74 * fTemp4) + (fSlow75 * fTemp5)) + (fSlow76 * fTemp6)) + (fSlow77 * fTemp7)) + (fSlow78 * fTemp8)) + (fSlow79 * fTemp9)) + (fSlow80 * fTemp10))));
			fVec39[IOTA&1048575] = fTemp295;
			iRec67[0] = ((iTemp14 * iRec67[1]) + (iSlow81 * iTemp13));
			iRec68[0] = ((iTemp17 * iRec68[1]) + (iSlow81 * iTemp16));
			double fTemp296 = ((0.5 * (fVec0[0] * fVec39[(IOTA-int((int(iRec67[0]) & 1048575)))&1048575])) + (fVec2[0] * fVec39[(IOTA-int((int(iRec68[0]) & 1048575)))&1048575]));
			int iTemp297 = (fTemp296 > 1);
			int iTemp298 = (fTemp296 < -1);
			double fTemp299 = ((iTemp297 + ((fTemp296 * (1 - iTemp298)) * (1 - iTemp297))) - iTemp298);
			fVec40[IOTA&262143] = fTemp299;
			double fTemp300 = (fRec70[1] + (fSlow82 / fTemp23));
			fRec70[0] = (fTemp300 - floor(fTemp300));
			double fTemp301 = (fRec70[0] - floor(fRec70[0]));
			fVec41[0] = fTemp301;
			int iTemp302 = (fVec41[0] > 0.001);
			int iTemp303 = (fVec41[1] <= 0.001);
			fRec69[0] = ((fRec69[1] * (1 - (iTemp302 * iTemp303))) + ((fRec22[0] * iTemp302) * iTemp303));
			double fTemp304 = (fConst4 * (fRec69[0] * fVec41[0]));
			int iTemp305 = int(fTemp304);
			double fTemp306 = floor(fTemp304);
			double fTemp307 = (0.5 * fVec41[0]);
			double fTemp308 = (65536.0 * (fTemp307 - floor(fTemp307)));
			int iTemp309 = int(fTemp308);
			double fTemp310 = ftbl0[iTemp309];
			double fTemp311 = (fRec70[0] + (0.25 - floor((fRec70[0] + 0.25))));
			fVec42[0] = fTemp311;
			int iTemp312 = (fVec42[0] > 0.001);
			int iTemp313 = (fVec42[1] <= 0.001);
			fRec71[0] = ((fRec71[1] * (1 - (iTemp312 * iTemp313))) + ((fRec22[0] * iTemp312) * iTemp313));
			double fTemp314 = (fConst4 * (fRec71[0] * fVec42[0]));
			int iTemp315 = int(fTemp314);
			double fTemp316 = floor(fTemp314);
			double fTemp317 = (0.5 * fVec42[0]);
			double fTemp318 = (65536.0 * (fTemp317 - floor(fTemp317)));
			int iTemp319 = int(fTemp318);
			double fTemp320 = ftbl0[iTemp319];
			double fTemp321 = (fRec70[0] + (0.5 - floor((fRec70[0] + 0.5))));
			fVec43[0] = fTemp321;
			int iTemp322 = (fVec43[0] > 0.001);
			int iTemp323 = (fVec43[1] <= 0.001);
			fRec72[0] = ((fRec72[1] * (1 - (iTemp322 * iTemp323))) + ((fRec22[0] * iTemp322) * iTemp323));
			double fTemp324 = (fConst4 * (fRec72[0] * fVec43[0]));
			int iTemp325 = int(fTemp324);
			double fTemp326 = floor(fTemp324);
			double fTemp327 = (0.5 * fVec43[0]);
			double fTemp328 = (65536.0 * (fTemp327 - floor(fTemp327)));
			int iTemp329 = int(fTemp328);
			double fTemp330 = ftbl0[iTemp329];
			double fTemp331 = (fRec70[0] + (0.75 - floor((fRec70[0] + 0.75))));
			fVec44[0] = fTemp331;
			int iTemp332 = (fVec44[0] > 0.001);
			int iTemp333 = (fVec44[1] <= 0.001);
			fRec73[0] = ((fRec73[1] * (1 - (iTemp332 * iTemp333))) + ((fRec22[0] * iTemp332) * iTemp333));
			double fTemp334 = (fConst4 * (fRec73[0] * fVec44[0]));
			int iTemp335 = int(fTemp334);
			double fTemp336 = floor(fTemp334);
			double fTemp337 = (0.5 * fVec44[0]);
			double fTemp338 = (65536.0 * (fTemp337 - floor(fTemp337)));
			int iTemp339 = int(fTemp338);
			double fTemp340 = ftbl0[iTemp339];
			fRec6[0] = ((0.5 * fVec40[IOTA&262143]) + (0.25 * ((((((fVec40[(IOTA-int((iTemp305 & 262143)))&262143] * (fTemp306 + (1 - fTemp304))) + ((fTemp304 - fTemp306) * fVec40[(IOTA-int((int((iTemp305 + 1)) & 262143)))&262143])) * (fTemp310 + ((fTemp308 - floor(fTemp308)) * (ftbl0[((iTemp309 + 1) % 65536)] - fTemp310)))) + (((fVec40[(IOTA-int((iTemp315 & 262143)))&262143] * (fTemp316 + (1 - fTemp314))) + ((fTemp314 - fTemp316) * fVec40[(IOTA-int((int((iTemp315 + 1)) & 262143)))&262143])) * (fTemp320 + ((fTemp318 - floor(fTemp318)) * (ftbl0[((iTemp319 + 1) % 65536)] - fTemp320))))) + (((fVec40[(IOTA-int((iTemp325 & 262143)))&262143] * (fTemp326 + (1 - fTemp324))) + ((fTemp324 - fTemp326) * fVec40[(IOTA-int((int((iTemp325 + 1)) & 262143)))&262143])) * (fTemp330 + ((fTemp328 - floor(fTemp328)) * (ftbl0[((iTemp329 + 1) % 65536)] - fTemp330))))) + (((fVec40[(IOTA-int((iTemp335 & 262143)))&262143] * (fTemp336 + (1 - fTemp334))) + ((fTemp334 - fTemp336) * fVec40[(IOTA-int((int((iTemp335 + 1)) & 262143)))&262143])) * (fTemp340 + ((fTemp338 - floor(fTemp338)) * (ftbl0[((iTemp339 + 1) % 65536)] - fTemp340)))))));
			fRec74[0] = (fSlow83 + (fSlow0 * fRec74[1]));
			output0[i] = (FAUSTFLOAT)(fRec0[0] * fRec74[0]);
			fRec75[0] = (fSlow84 + (fSlow0 * fRec75[1]));
			output1[i] = (FAUSTFLOAT)(fRec1[0] * fRec75[0]);
			fRec76[0] = (fSlow85 + (fSlow0 * fRec76[1]));
			output2[i] = (FAUSTFLOAT)(fRec2[0] * fRec76[0]);
			fRec77[0] = (fSlow86 + (fSlow0 * fRec77[1]));
			output3[i] = (FAUSTFLOAT)(fRec3[0] * fRec77[0]);
			fRec78[0] = (fSlow87 + (fSlow0 * fRec78[1]));
			output4[i] = (FAUSTFLOAT)(fRec4[0] * fRec78[0]);
			fRec79[0] = (fSlow88 + (fSlow0 * fRec79[1]));
			output5[i] = (FAUSTFLOAT)(fRec5[0] * fRec79[0]);
			fRec80[0] = (fSlow89 + (fSlow0 * fRec80[1]));
			output6[i] = (FAUSTFLOAT)(fRec6[0] * fRec80[0]);
			// post processing
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			fRec6[1] = fRec6[0];
			fRec73[1] = fRec73[0];
			fVec44[1] = fVec44[0];
			fRec72[1] = fRec72[0];
			fVec43[1] = fVec43[0];
			fRec71[1] = fRec71[0];
			fVec42[1] = fVec42[0];
			fRec69[1] = fRec69[0];
			fVec41[1] = fVec41[0];
			fRec70[1] = fRec70[0];
			iRec68[1] = iRec68[0];
			iRec67[1] = iRec67[0];
			fRec66[1] = fRec66[0];
			fRec5[1] = fRec5[0];
			fRec65[1] = fRec65[0];
			fVec38[1] = fVec38[0];
			fRec64[1] = fRec64[0];
			fVec37[1] = fVec37[0];
			fRec63[1] = fRec63[0];
			fVec36[1] = fVec36[0];
			fRec61[1] = fRec61[0];
			fVec35[1] = fVec35[0];
			fRec62[1] = fRec62[0];
			iRec60[1] = iRec60[0];
			iRec59[1] = iRec59[0];
			fRec58[1] = fRec58[0];
			fRec4[1] = fRec4[0];
			fRec57[1] = fRec57[0];
			fVec32[1] = fVec32[0];
			fRec56[1] = fRec56[0];
			fVec31[1] = fVec31[0];
			fRec55[1] = fRec55[0];
			fVec30[1] = fVec30[0];
			fRec53[1] = fRec53[0];
			fVec29[1] = fVec29[0];
			fRec54[1] = fRec54[0];
			iRec52[1] = iRec52[0];
			iRec51[1] = iRec51[0];
			fRec50[1] = fRec50[0];
			fRec3[1] = fRec3[0];
			fRec49[1] = fRec49[0];
			fVec26[1] = fVec26[0];
			fRec48[1] = fRec48[0];
			fVec25[1] = fVec25[0];
			fRec47[1] = fRec47[0];
			fVec24[1] = fVec24[0];
			fRec45[1] = fRec45[0];
			fVec23[1] = fVec23[0];
			fRec46[1] = fRec46[0];
			iRec44[1] = iRec44[0];
			iRec43[1] = iRec43[0];
			fRec42[1] = fRec42[0];
			fRec2[1] = fRec2[0];
			fRec41[1] = fRec41[0];
			fVec20[1] = fVec20[0];
			fRec40[1] = fRec40[0];
			fVec19[1] = fVec19[0];
			fRec39[1] = fRec39[0];
			fVec18[1] = fVec18[0];
			fRec37[1] = fRec37[0];
			fVec17[1] = fVec17[0];
			fRec38[1] = fRec38[0];
			iRec36[1] = iRec36[0];
			iRec35[1] = iRec35[0];
			fRec34[1] = fRec34[0];
			fRec1[1] = fRec1[0];
			fRec33[1] = fRec33[0];
			fVec14[1] = fVec14[0];
			fRec32[1] = fRec32[0];
			fVec13[1] = fVec13[0];
			fRec31[1] = fRec31[0];
			fVec12[1] = fVec12[0];
			fRec29[1] = fRec29[0];
			fVec11[1] = fVec11[0];
			fRec30[1] = fRec30[0];
			iRec28[1] = iRec28[0];
			iRec27[1] = iRec27[0];
			fRec26[1] = fRec26[0];
			fRec0[1] = fRec0[0];
			fRec25[1] = fRec25[0];
			fVec8[1] = fVec8[0];
			fRec24[1] = fRec24[0];
			fVec7[1] = fVec7[0];
			fRec23[1] = fRec23[0];
			fVec6[1] = fVec6[0];
			fRec19[1] = fRec19[0];
			fVec5[1] = fVec5[0];
			fRec20[1] = fRec20[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fVec4[1] = fVec4[0];
			iRec18[1] = iRec18[0];
			fVec2[1] = fVec2[0];
			iRec17[1] = iRec17[0];
			IOTA = IOTA+1;
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fVec0[1] = fVec0[0];
			fRec8[1] = fRec8[0];
		}
	}
};


double 	mydsp::ftbl0[65536];

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

/* Faust code wrapper ------- */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include "jpatcher_api.h"
#include <string.h>

#define ASSIST_INLET 	1  		/* should be defined somewhere ?? */
#define ASSIST_OUTLET 	2		/* should be defined somewhere ?? */

#define EXTERNAL_VERSION "0.60"

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_GUI_H
#define FAUST_GUI_H

/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

ringbuffer_t *ringbuffer_create(size_t sz);
void ringbuffer_free(ringbuffer_t *rb);
void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_read_space(const ringbuffer_t *rb);
int ringbuffer_mlock(ringbuffer_t *rb);
void ringbuffer_reset(ringbuffer_t *rb);
void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two.  */

inline ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

inline void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

inline int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading.  This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

inline size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing.  This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

inline size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader.  Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance.  Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

inline size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer.  Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

inline void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

inline void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader.  `vec' is an array of two places.  Set
   the values at `vec' to hold the current readable data at `rb'.  If
   the readable data is in one segment the second segment has zero
   length.  */

inline void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer.  `vec' is an array of two places.  Set
   the values at `vec' to hold the current writeable data at `rb'.  If
   the writeable data is in one segment the second segment has zero
   length.  */

inline void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__

#include <list>
#include <map>
#include <vector>

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

class clist : public std::list<uiItem*>
{
    public:
    
        virtual ~clist();
        
};

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*>  fGuiList;
        zmap                    fZoneMap;
        bool                    fStopped;
        
     public:
            
        GUI() : fStopped(false) 
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all 
            zmap::iterator g;
            for (g = fZoneMap.begin(); g != fZoneMap.end(); g++) {
                delete (*g).second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItem* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }

        void updateAllZones();
        
        void updateZone(FAUSTFLOAT* z);
        
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data);
        virtual void show() {};	
        virtual bool run() { return false; };
    
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {};
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* , const char* , const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition
 */

class uiItem
{
    protected:
          
        GUI*            fGUI;
        FAUSTFLOAT*     fZone;
        FAUSTFLOAT      fCache;

        uiItem(GUI* ui, FAUSTFLOAT* zone):fGUI(ui), fZone(zone), fCache(FAUSTFLOAT(-123456.654321))
        { 
            ui->registerZone(zone, this); 
        }

    public:

        virtual ~uiItem() 
        {}

        void modifyZone(FAUSTFLOAT v) 	
        { 
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
                
        FAUSTFLOAT		cache()	{ return fCache; }
        virtual void 	reflectZone() = 0;	
};

/**
 * User Interface item owned (and so deleted) by external code
 */

class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item
 */

struct uiCallbackItem : public uiItem
{
	uiCallback	fCallback;
	void*		fData;
	
	uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data) 
			: uiItem(ui, zone), fCallback(foo), fData(data) {}
	
	virtual void reflectZone() 
    {		
		FAUSTFLOAT 	v = *fZone;
		fCache = v; 
		fCallback(v, fData);	
	}
};

/**
 * Allows to group a set of zones.
 */
 
class uiGroupItem : public uiItem 
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            std::vector<FAUSTFLOAT*>::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                (*(*it)) = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

/**
 * Update all user items reflecting zone z
 */

inline void GUI::updateZone(FAUSTFLOAT* z)
{
	FAUSTFLOAT v = *z;
	clist* l = fZoneMap[z];
	for (clist::iterator c = l->begin(); c != l->end(); c++) {
		if ((*c)->cache() != v) (*c)->reflectZone();
	}
}

/**
 * Update all user items not up to date
 */

inline void GUI::updateAllZones()
{
	for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
		FAUSTFLOAT* z = m->first;
		clist*	l = m->second;
        if (z) {
            FAUSTFLOAT	v = *z;
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
	}
}

inline void GUI::addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data) 
{ 
	new uiCallbackItem(this, zone, foo, data); 
};

inline clist::~clist() 
{
    std::list<uiItem*>::iterator it;
    for (it = begin(); it != end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

// For precise timestamped control
struct DatedControl {

    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}

};
  
#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <string>
#include <utility>
#include <iostream>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <algorithm>

class MapUI;

//----------------------------------------------------------------
//  MIDI processor definition
//----------------------------------------------------------------

class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 127)
        {
            keyOff(channel, pitch, velocity);
        }
        
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
       
        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
        
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
       
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        // MIDI sync
        virtual void start_sync(double date)  {}
        virtual void stop_sync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return 0; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}

        enum MidiStatus {

            // channel voice messages
            MIDI_NOTE_OFF           = 0x80,
            MIDI_NOTE_ON            = 0x90,
            MIDI_CONTROL_CHANGE     = 0xB0,
            MIDI_PROGRAM_CHANGE     = 0xC0,
            MIDI_PITCH_BEND         = 0xE0,
            MIDI_AFTERTOUCH         = 0xD0,	// aka channel pressure
            MIDI_POLY_AFTERTOUCH    = 0xA0,	// aka key pressure
            MIDI_CLOCK              = 0xF8,
            MIDI_START              = 0xFA,
            MIDI_STOP               = 0xFC

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

//----------------------------------------------------------------
//  Base class for MIDI API handling
//----------------------------------------------------------------

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;

    public:

        midi_handler(const std::string& name = "MIDIHandler"):fName(name) {}
        virtual ~midi_handler() {}

        virtual void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        virtual void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        virtual bool start_midi() { return true; }
        virtual void stop_midi() {}
        
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->start_sync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stop_sync(time);
                }
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->progChange(time, channel, data1);
                }
            } else if (type == MIDI_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->chanPress(time, channel, data1);
                }
            }
        }

        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF || ((type == MIDI_NOTE_ON) && (data2 == 0))) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOff(time, channel, data1, data2);
                }
            } else if (type == MIDI_NOTE_ON) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            } else if (type == MIDI_CONTROL_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            } else if (type == MIDI_PITCH_BEND) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 * 128.0) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }


};

#endif // __midi__
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
								ValueConverter.h
							    (GRAME, © 2015)

Set of conversion objects used to map user interface values (for example a gui slider
delivering values between 0 and 1) to faust values (for example a vslider between
20 and 20000) using a log scale.

-- Utilities

Range(lo,hi) : clip a value x between lo and hi
Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2

-- Value Converters

ValueConverter::ui2faust(x)
ValueConverter::faust2ui(x)

-- ValueConverters used for sliders depending of the scale

LinearValueConverter(umin, umax, fmin, fmax)
LogValueConverter(umin, umax, fmin, fmax)
ExpValueConverter(umin, umax, fmin, fmax)

-- ValueConverters used for accelerometers based on 3 points

AccUpConverter(amin, amid, amax, fmin, fmid, fmax)		-- curve 0
AccDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 1
AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 2
AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 3

-- lists of ZoneControl are used to implement accelerometers metadata for each axes

ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter

-- ZoneReader are used to implement screencolor metadata

ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>

//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef   		with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef				with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class Interpolator
{
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class Interpolator3pt
{

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class ValueConverter
{

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) = 0;
        virtual double faust2ui(double x) = 0;
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and faust values
//--------------------------------------------------------------------------------------
class LinearValueConverter : public ValueConverter
{

    private:

        Interpolator fUI2F;
        Interpolator fF2UI;

    public:

        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}

        LinearValueConverter() :
            fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) {	return fUI2F(x); }
        virtual double faust2ui(double x) {	return fF2UI(x); }

};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and faust values
//--------------------------------------------------------------------------------------
class LogValueConverter : public LinearValueConverter
{

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class ExpValueConverter : public LinearValueConverter
{

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, exp(fmin), exp(fmax))
        {}

        virtual double ui2faust(double x) { return log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(exp(x)); }

};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class UpdatableValueConverter : public ValueConverter {

    protected:

        bool fActive;

    public:

        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}

        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;

        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class AccUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmid,fmax);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amin,amid,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class AccDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmid,fmin);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amax,amid,amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class AccUpDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmax,fmin);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class AccDownUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmin,fmax);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class ZoneControl
{

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class ConverterZoneControl : public ZoneControl
{

    private:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* valueConverter) : ZoneControl(zone), fValueConverter(valueConverter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        void update(double v) { *fZone = fValueConverter->ui2faust(v); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class CurveZoneControl : public ZoneControl
{

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                delete(*it);
            }
        }
        void update(double v) { if (fValueConverters[fCurve]->getActive()) *fZone = fValueConverters[fCurve]->ui2faust(v); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                (*it)->setActive(on_off);
            }
        }

        int getCurve() { return fCurve; }
};

class ZoneReader
{

    private:

        FAUSTFLOAT*     fZone;
        Interpolator    fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue() {
            if (fZone != 0) {
                return (int)fInterpolator(*fZone);
            } else {
                return 127;
            }
        }

};

#endif

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/*****************************************************************************
* Helper code for MIDI meta and polyphonic 'nvoices' parsing
******************************************************************************/

struct MidiMeta : public Meta, public std::map<std::string, std::string>
{
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        if (this->find(key) != this->end()) {
            return (*this)[key];
        } else {
            return def;
        }
    }
    
    static void analyse(dsp* tmp_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        tmp_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        tmp_dsp->metadata(&meta);
        std::string numVoices = meta.get("nvoices", "0");
        nvoices = atoi(numVoices.c_str());
        if (nvoices < 0) nvoices = 0;
    #endif
    }
};

/*******************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend 
 * start/stop/clock meta data is handled.
 ******************************************************************************/
 
class uiMidiItem : public uiItem {
 
    protected:
    
         midi* fMidiOut;
         bool fInputCtrl;

    public:
    
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input)
            :uiItem(ui, zone), fMidiOut(midi_out), fInputCtrl(input) {}
        virtual ~uiMidiItem() {}
 
};
 
class uiMidiTimedItem : public uiMidiItem
{
    protected:
    
        bool fDelete;
   
    public:
       
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiMidiTimedItem() 
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }

        void modifyZone(double date, FAUSTFLOAT v) 	
        { 
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                std::cerr << "ringbuffer_write error DatedControl" << std::endl;
            }
        }
        
        // TODO
        virtual void reflectZone() {}

};

// MIDI sync

class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->start_sync(0);
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stop_sync(0);
            }
        }
};

class uiMidiClock : public uiMidiTimedItem
{

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
        
        void modifyZone(double date, FAUSTFLOAT v) 	
        { 
            if (fInputCtrl) {
                fState = !fState;
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
            }
        }
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
};

class uiMidiProgChange : public uiMidiItem
{
    private:
        
        int fPgm;
  
    public:
    
        uiMidiProgChange(midi* midi_out, int pgm, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPgm(pgm)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->progChange(0, fPgm);
            }
        }
        
};

class uiMidiChanPress : public uiMidiItem
{
    private:
        
        int fPress;
  
    public:
    
        uiMidiChanPress(midi* midi_out, int press, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPress(press)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->chanPress(0, fPress);
            }
        }
        
};

class uiMidiCtrlChange : public uiMidiItem
{
    private:
    
        int fCtrl;
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fCtrl(ctrl), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->ctrlChange(0, fCtrl, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiItem
{

    private:
    	
		// currently, the range is of pitchwheel if fixed (-2/2 semitones)
        FAUSTFLOAT wheel2bend(float v)
        {
            return pow(2.0,(v/16383.0*4-2)/12);
        }

        int bend2wheel(float v)
        {
            return (int)((12*log(v)/log(2)+2)/4*16383);
        }
 
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, bend2wheel(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(wheel2bend(v));
            }
        }
 
};

class uiMidiKeyOn : public uiMidiItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOn(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyOff : public uiMidiItem
{

    private:
        
        int fKeyOff;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOff(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOff(0, fKeyOff, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyPress : public uiMidiItem
{

    private:
        
        int fKey;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKey(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKey, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class MapUI;

class MidiUI : public GUI, public midi
{

    protected:
    
        std::map <int, std::vector<uiMidiCtrlChange*> > fCtrlChangeTable;
        std::map <int, std::vector<uiMidiProgChange*> > fProgChangeTable;
        std::map <int, std::vector<uiMidiChanPress*> >  fChanPressTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyOnTable;
        std::map <int, std::vector<uiMidiKeyOff*> >     fKeyOffTable;
        std::map <int, std::vector<uiMidiKeyPress*> >   fKeyPressTable;
        std::vector<uiMidiPitchWheel*>                  fPitchWheelTable;
        
        std::vector<uiMidiStart*>   fStartTable;
        std::vector<uiMidiStop*>    fStopTable;
        std::vector<uiMidiClock*>   fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &num) == 1) {
                            fProgChangeTable[num].push_back(new uiMidiProgChange(fMidiHandler, num, this, zone, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &num) == 1) {
                            fChanPressTable[num].push_back(new uiMidiChanPress(fMidiHandler, num, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pitchwheel") == 0 
                            || strcmp(fMetaAux[i].second.c_str(), "pitchbend") == 0) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
                        // MIDI sync
                        } else if (strcmp(fMetaAux[i].second.c_str(), "start") == 0) {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "stop") == 0) {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "clock") == 0) {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:

        MidiUI(midi_handler* midi_handler)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
        }
        
        bool run() { return fMidiHandler->start_midi(); }
        void stop() { fMidiHandler->stop_midi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API 
        
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            if (fKeyOnTable.find(note) != fKeyOnTable.end()) {
                for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                    fKeyOnTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            return 0;
        }
        
        void keyOff(double date,  int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                    fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
        }
           
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            if (fCtrlChangeTable.find(ctrl) != fCtrlChangeTable.end()) {
                for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                    fCtrlChangeTable[ctrl][i]->modifyZone(FAUSTFLOAT(value));
                }
            } 
        }
        
        void progChange(double date, int channel, int pgm)
        {
            if (fProgChangeTable.find(pgm) != fProgChangeTable.end()) {
                for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                    fProgChangeTable[pgm][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                fPitchWheelTable[i]->modifyZone(FAUSTFLOAT(wheel));
            }
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            if (fKeyPressTable.find(pitch) != fKeyPressTable.end()) {
                for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                    fKeyPressTable[pitch][i]->modifyZone(FAUSTFLOAT(press));
                }
            } 
        }
        
        void chanPress(double date, int channel, int press)
        {
            if (fChanPressTable.find(press) != fChanPressTable.end()) {
                for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                    fChanPressTable[press][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void start_sync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stop_sync(double date)
        {
            for (unsigned int i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (unsigned int i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.

 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.

 ************************************************************************
 ************************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <math.h>
#include <float.h>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <map>
#include <string>


/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        FAUSTFLOAT getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return FAUSTFLOAT(0);
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return fPathZoneMap.size(); }
        
        std::string getParamAddress(int index)
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
};

#endif // FAUST_MAPUI_H
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>

/************************************************************************
 ************************************************************************
 FAUST compiler
 Copyright (C) 2003-2015 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std;

struct itemInfo {
    std::string type;
    std::string label;
    std::string address;
    std::string init;
    std::string min;
    std::string max;
    std::string step;
    std::vector<std::pair<std::string, std::string> > meta;
};

bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values);
bool parseMenuItem(const char*& p, string& name, double& value);

void skipBlank(const char*& p);
bool parseChar(const char*& p, char x);
bool parseWord(const char*& p, const char* w);
bool parseString(const char*& p, char quote, string& s);
bool parseSQString(const char*& p, string& s);
bool parseDQString(const char*& p, string& s);
bool parseDouble(const char*& p, double& x);

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
inline bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values)
{
    vector<string> tmpnames;
    vector<double> tmpvalues;

    const char* saved = p;

    if (parseChar(p, '{')) {
        do {
            string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
inline bool parseMenuItem(const char*& p, string& name, double& value)
{
    const char* saved = p;
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
inline void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
inline bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
inline bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
inline bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part

    bool valid = false;   // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail

    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    if (valid)  {
        x = sign*(ipart + dpart/dcoef);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseString(const char*& p, char quote, string& s)
{
    string str;
    skipBlank(p);
 
    const char* saved = p;
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseSQString(const char*& p, string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseDQString(const char*& p, string& s)
{
    return parseString(p, '"', s);
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
//
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, std::map<std::string, std::string>& metadatas)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && parseDQString(p, value);
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
//
static bool parseUI(const char*& p, std::vector<itemInfo*>& uiItems, int& numItems)
{
    if (parseChar(p, '{')) {
        
        std::string label;
        std::string value;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo* item = new itemInfo;
                        item->type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->label = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->address = value;
                    }
                }
                
                else if (label == "meta") {
                    itemInfo* item = uiItems[numItems];
                    if (!parseItemMetaData(p, item->meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->init = value;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->min = value;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->max = value;
                    }
                }
                
                else if (label == "step"){
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->step = value;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do { 
                            if (!parseUI(p, uiItems, numItems)) {
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo* item = new itemInfo;
                            item->type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
                }
            } else {
                return false;
            }
            
        } while (tryChar(p, ','));
        
        return parseChar(p, '}');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
//

inline bool parseJson(const char*& p, std::map<std::string, std::string>& metadatas, std::vector<itemInfo*>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        if (parseGlobalMetaData(p, key, value, metadatas)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                metadatas[key] = value;
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

inline FAUSTFLOAT STR2REAL(const std::string& s) { return (strtod(s.c_str(), NULL)); }

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

struct JSONUIDecoder {

    std::string fName;
    
    std::map<std::string, std::string> fMetadatas; 
    std::vector<itemInfo*> fUiItems;     
    
    FAUSTFLOAT* fInControl;
    FAUSTFLOAT* fOutControl;
    
    std::string fJSON;
    
    int fNumInputs, fNumOutputs; 
    int fInputItems, fOutputItems; 

    JSONUIDecoder(const std::string& json) 
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        parseJson(p, fMetadatas, fUiItems);
        
        // fMetadatas will contain the "meta" section as well as <name : val>, <inputs : val>, <ouputs : val> pairs
        if (fMetadatas.find("name") != fMetadatas.end()) {
            fName = fMetadatas["name"];
            fMetadatas.erase("name");
        } else {
            fName = "";
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = atoi(fMetadatas["inputs"].c_str());
            fMetadatas.erase("inputs");
        } else {
            fNumInputs = -1;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = atoi(fMetadatas["outputs"].c_str());
            fMetadatas.erase("outputs");
        } else {
            fNumOutputs = -1;
        }
        
        vector<itemInfo*>::iterator it;
        fInputItems = 0;
        fOutputItems = 0;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            if (type == "vslider" || type == "hslider" || type == "nentry" || type == "button") {
                fInputItems++;
            } else if (type == "hbargraph" || type == "vbargraph") {
                fOutputItems++;          
            }
        }
        
        fInControl = new FAUSTFLOAT[fInputItems];
        fOutControl = new FAUSTFLOAT[fOutputItems];
    }
    
    virtual ~JSONUIDecoder() 
    {
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            delete(*it);
        }
        delete [] fInControl;
        delete [] fOutControl;
    }
    
    void metadata(Meta* m)
    {
        std::map<std::string, std::string>::iterator it;
        for (it = fMetadatas.begin(); it != fMetadatas.end(); it++) {
            m->declare((*it).first.c_str(), (*it).second.c_str());
        }
    }
   
    void buildUserInterface(UI* ui)
    {
        // To be sure the floats are correctly encoded
        char* tmp_local = setlocale(LC_ALL, NULL);
        setlocale(LC_ALL, "C");

        int counterIn = 0;
        int counterOut = 0;
        vector<itemInfo*>::iterator it;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            
            bool isInItem = false;
            bool isOutItem = false;
            string type = (*it)->type;
            
            FAUSTFLOAT init = STR2REAL((*it)->init);
            FAUSTFLOAT min = STR2REAL((*it)->min);
            FAUSTFLOAT max = STR2REAL((*it)->max);
            FAUSTFLOAT step = STR2REAL((*it)->step);
            
            if (type == "vslider" || type == "hslider" || type == "nentry" || type == "button") {
                isInItem = true;
            } else if (type == "hbargraph" || type == "vbargraph") {
                isOutItem = true;        
            }
            
            // Meta data declaration for input items
            if ((*it)->type.find("group") == string::npos && (*it)->type.find("bargraph") == string::npos && (*it)->type != "close") {
                fInControl[counterIn] = init;
                for (int i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fInControl[counterIn], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if ((*it)->type.find("bargraph") != string::npos) {
                fOutControl[counterOut] = init;
                for (int i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fOutControl[counterOut], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (int i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(0, (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui->openHorizontalBox((*it)->label.c_str());
            } else if (type == "vgroup") { 
                ui->openVerticalBox((*it)->label.c_str());
            } else if (type == "tgroup") {
                ui->openTabBox((*it)->label.c_str());
            } else if (type == "vslider") {
                ui->addVerticalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "hslider") {
                ui->addHorizontalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);            
            } else if (type == "checkbox") {
                ui->addCheckButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "hbargraph") {
                ui->addHorizontalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "vbargraph") {
                ui->addVerticalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "nentry") {
                ui->addNumEntry((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "button") {
                ui->addButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "close") {
                ui->closeBox();
            }
                
            if (isInItem) {
                counterIn++;
            }
                
            if (isOutItem) {
                counterOut++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
};

//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

class proxy_dsp : public dsp {

    private:
    
        int fSamplingFreq;
        JSONUIDecoder* fDecoder;
        
    public:
    
        proxy_dsp(const string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSamplingFreq = -1;
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSamplingFreq = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
       
        virtual int getNumInputs() 	{ return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int samplingRate) { fSamplingFreq = samplingRate; }
        virtual void instanceInit(int samplingRate) {}
        virtual void instanceConstants(int samplingRate) {}
        virtual void instanceResetUserInterface() {}
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSamplingFreq; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.001
#define MIX_BUFFER_SIZE   16384

#define FLOAT_MAX(a, b) (((a) < (b)) ? (b) : (a))

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static inline bool endsWith(std::string const& str, std::string const& end)
{
    size_t l1 = str.length();
    size_t l2 = end.length();
    return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
}

static inline double midiToFreq(double note)
{
    return 440.0 * pow(2.0, (note-69.0)/12.0);
}

static inline unsigned int isPowerOfTwo(unsigned int n)
{
    return !(n & (n - 1));
}

/**
 * Allows to control zones in a grouped manner.
 */

class GroupUI : public GUI, public PathBuilder
{

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!endsWith(label, "/gate")
                && !endsWith(label, "/freq")
                && !endsWith(label, "/gain")) {

                // Groups all controller except 'freq', 'gate', and 'gain'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        };
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        };

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */

struct dsp_voice : public MapUI, public decorator_dsp {

    int fNote;              // Playing note actual pitch
    int fDate;              // KeyOn date
    bool fTrigger;          // True if stolen note and need for envelop trigger
    FAUSTFLOAT fLevel;      // Last audio block level
    std::string fGatePath;  // Path of 'gate' control
    std::string fGainPath;  // Path of 'gain' control
    std::string fFreqPath;  // Path of 'freq' control

    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
        extractPaths(fGatePath, fFreqPath, fGainPath);
    }

    void extractPaths(std::string& gate, std::string& freq, std::string& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate = path;
            } else if (endsWith(path, "/freq")) {
                freq = path;
            } else if (endsWith(path, "/gain")) {
                gain = path;
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, float(velocity)/127.f);
        fNote = pitch;
        fTrigger = true; // so that envelop is always re-initialized
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, velocity);
        fNote = pitch;
        fTrigger = true; // so that envelop is always re-initialized
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        setParamValue(fGatePath, FAUSTFLOAT(0));
        if (hard) {
            // Stop immediately
            fNote = kFreeVoice;
            fTrigger = false;
        } else {
            // Release voice
            fNote = kReleaseVoice;
        }
    }

    void play(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (fTrigger) {
            // New note, so trigger it
            trigger(count, inputs, outputs);
        } else {
            // Compute the voice
            compute(count, inputs, outputs);
        }
    }

    void trigger(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        setParamValue(fGatePath, FAUSTFLOAT(0));
        computeSlice(0, 1, inputs, outputs);
        setParamValue(fGatePath, FAUSTFLOAT(1));
        computeSlice(1, count - 1, inputs, outputs);
        fTrigger = false;
    }

    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (slice > 0) {
            FAUSTFLOAT** inputs_slice = (FAUSTFLOAT**)alloca(getNumInputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < getNumInputs(); chan++) {
                inputs_slice[chan] = &(inputs[chan][offset]);
            }

            FAUSTFLOAT** outputs_slice = (FAUSTFLOAT**)alloca(getNumOutputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                outputs_slice[chan] = &(outputs[chan][offset]);
            }

            compute(slice, inputs_slice, outputs_slice);
        }
    }

};

/**
 * A group of voices.
 */

struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (int i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (int i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // In not group, also add individual voices UI
            if (!fGroupControl) {
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 31, ((fVoiceTable.size() < 8) ? "Voice%d" : "V%d"), i+1);
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Polyphonic DSP : group a set of DSP to be played together or triggered by MIDI.
 */

class mydsp_poly : public decorator_dsp, public dsp_voice_group, public midi {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        inline FAUSTFLOAT mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = FLOAT_MAX(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }

        inline void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }

        inline int getVoice(int note, bool steal = false)
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == note) {
                    if (steal) {
                        fVoiceTable[i]->fDate = fDate++;
                    }
                    return i;
                }
            }

            if (steal) {
                int voice_release = kNoVoice;
                int voice_playing = kNoVoice;
                int oldest_date_release = INT_MAX;
                int oldest_date_playing = INT_MAX;

                // Scan all voices
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    if (fVoiceTable[i]->fNote == kReleaseVoice) {
                        // Keeps oldest release voice
                        if (fVoiceTable[i]->fDate < oldest_date_release) {
                            oldest_date_release = fVoiceTable[i]->fDate;
                            voice_release = i;
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = i;
                        }
                    }
                }

                // Then decide which one to steal
                if (oldest_date_release != INT_MAX) {
                    std::cout << "Steal release voice : voice_date " << fVoiceTable[voice_release]->fDate << " cur_date = " << fDate << " voice = " << voice_release << std::endl;
                    fVoiceTable[voice_release]->fDate = fDate++;
                    fVoiceTable[voice_release]->fTrigger = true;
                    return voice_release;
                } else if (oldest_date_playing != INT_MAX) {
                    std::cout << "Steal playing voice : voice_date " << fVoiceTable[voice_playing]->fDate << " cur_date = " << fDate << " voice = " << voice_playing << std::endl;
                    fVoiceTable[voice_playing]->fDate = fDate++;
                    fVoiceTable[voice_playing]->fTrigger = true;
                    return voice_playing;
                } else {
                    assert(false);
                    return kNoVoice;
                }

            } else {
                return kNoVoice;
            }
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        inline bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                std::cout << "DSP is not polyphonic...\n";
                return false;
            }
        }

        // Always returns a voice
        int newVoiceAux()
        {
            int voice = getVoice(kFreeVoice, true);
            assert(voice != kNoVoice);
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }

    public:

        /**
         * Constructor.
         *
         * @param dsp - the dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true):decorator_dsp(dsp), dsp_voice_group(panic, this, control, group)
        {
            fDate = 0;

            // Create voices
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int i = 0; i < getNumOutputs(); i++) {
                fMixBuffer[i] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~mydsp_poly()
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                delete[] fMixBuffer[i];
            }
            delete[] fMixBuffer;
        }

        // DSP API
    
        void buildUserInterface(UI* ui_interface)
        {
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int samplingRate)
        {
            // Init voices
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(samplingRate);
            }
        }

        void instanceInit(int samplingRate)
        {
            // Init voices
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceInit(samplingRate);
            }
        }

        void instanceConstants(int samplingRate)
        {
            // Init voices
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(samplingRate);
            }
        }

        void instanceResetUserInterface()
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), fVoiceTable.size(), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count < MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->play(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        if ((voice->fLevel < VOICE_STOP_LEVEL) && (voice->fNote == kReleaseVoice)) {
                            voice->fNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, outputs);
                }
            }
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }

        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[newVoiceAux()];
        }

        void deleteVoice(MapUI* voice)
        {
            std::vector<dsp_voice*>::iterator it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                (*it)->keyOff();
            } else {
                std::cout << "Voice not found\n";
            }
        }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = newVoiceAux();
                fVoiceTable[voice]->keyOn(pitch, velocity);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    std::cout << "Playing pitch = " << pitch << " not found\n";
                }
            }
        }

        void pitchWheel(int channel, int wheel)
        {}

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        void progChange(int channel, int pgm)
        {}

        void keyPress(int channel, int pitch, int press)
        {}

        void chanPress(int channel, int press)
        {}

        void ctrlChange14bits(int channel, int ctrl, int value)
        {}

        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }

};

#endif // __poly_dsp__

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

static const char* getCodeSize()
{
    int tmp;
    return (sizeof(&tmp) == 8) ? "64 bits" : "32 bits";
}

class mspUI;

struct Max_Meta1 : Meta
{
    int fCount;
    
    Max_Meta1():fCount(0)
    {}
     
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            fCount++;
        }
    }
};

struct Max_Meta2 : Meta
{
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            post("%s : %s", key, value);
        }
    }
};

/*--------------------------------------------------------------------------*/
typedef struct faust
{
    t_pxobject m_ob;
    t_atom *m_seen, *m_want;
    map<string, vector <t_object*> > m_output_table;
    short m_where;
    bool m_mute;
    void** m_args;
    mspUI* m_dspUI;
    dsp* m_dsp;
    char* m_json;
    t_systhread_mutex m_mutex;    
    int m_Inputs;
    int m_Outputs;
#ifdef MIDICTRL
    MidiUI* m_midiUI;
    midi_handler* m_midiHandler;
#endif
} t_faust;

void* faust_class;

void faust_create_jsui(t_faust* x);
void faust_make_json(t_faust* x);

/*--------------------------------------------------------------------------*/
class mspUIObject {

	protected:

		string fLabel;
		FAUSTFLOAT* fZone;

		FAUSTFLOAT range(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT val) {return (val < min) ? min : (val > max) ? max : val;}

	public:

		mspUIObject(const string& label, FAUSTFLOAT* zone):fLabel(label),fZone(zone) {}
		virtual ~mspUIObject() {}

		virtual void setValue(FAUSTFLOAT f) {*fZone = range(0.0,1.0,f);}
        virtual FAUSTFLOAT getValue() { return *fZone; }
		virtual void toString(char* buffer) {}
		virtual string getName() {return fLabel;}
};

/*--------------------------------------------------------------------------*/
class mspCheckButton : public mspUIObject {

	public:

		mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspCheckButton() {}

		void toString(char* buffer)
		{
            sprintf(buffer, "CheckButton(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspButton : public mspUIObject {

	public:

		mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspButton() {}

		void toString(char* buffer)
		{
            sprintf(buffer, "Button(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspSlider : public mspUIObject {

	private:

		FAUSTFLOAT fInit;
		FAUSTFLOAT fMin;
		FAUSTFLOAT fMax;
		FAUSTFLOAT fStep;

	public:

		mspSlider(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
			:mspUIObject(label,zone),fInit(init),fMin(min),fMax(max),fStep(step) {}
		virtual ~mspSlider() {}

		void toString(char* buffer)
		{
            stringstream s; 
            s << "Slider(double): " << fLabel << " [init=" << fInit << ":min=" << fMin << ":max=" << fMax << ":step=" << fStep << ":cur=" << *fZone << "]";
            strcpy(buffer, s.str().c_str());
		}

		void setValue(FAUSTFLOAT f) {*fZone = range(fMin,fMax,f);}
};

/*--------------------------------------------------------------------------*/
class mspBargraph : public mspUIObject {
    
    private:
        
        FAUSTFLOAT fMin;
        FAUSTFLOAT fMax;
        FAUSTFLOAT fCurrent;
        
    public:
        
        mspBargraph(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        :mspUIObject(label,zone),fMin(min),fMax(max),fCurrent(*zone) {}
        virtual ~mspBargraph() {}
        
        void toString(char* buffer)
        {
            stringstream s; 
            s << "Bargraph(float): " << fLabel << " [min=" << fMin << ":max=" << fMax << ":cur=" << *fZone << "]";
            strcpy(buffer, s.str().c_str());
        }
        
        virtual FAUSTFLOAT getValue() 
        { 
            if (*fZone != fCurrent) {
                fCurrent = *fZone;
                return fCurrent;
            } else {
                return NAN; 
            }
        }
};

/*--------------------------------------------------------------------------*/

#define MULTI_SIZE  256

class mspUI : public UI
{
	private:

        map<string, mspUIObject*> fUITable1;       // Table using labels
        map<string, mspUIObject*> fUITable2;       // Table using complete path
        map<string, mspUIObject*> fUITable3;       // Table containing bargraph
       
        map<const char*, const char*> fDeclareTable;
        std::vector<std::string> fControlsLevel;
        
        FAUSTFLOAT* fMultiTable[MULTI_SIZE];
        int fMultiIndex;
        int fMultiControl;
        
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
        string createLabel(const char* label)
        {
            map<const char*, const char*>::reverse_iterator it;
            if (fDeclareTable.size() > 0) {
                unsigned int i = 0;
                string res = string(label);
                char sep = '[';
                for (it = fDeclareTable.rbegin(); it != fDeclareTable.rend(); it++, i++) {
                    res = res + sep + (*it).first + ":" + (*it).second;
                    sep = ',';
                }
                res += ']';
                fDeclareTable.clear();
                return res;
            } else {
                return string(label);
            }
        }

	public:
    
		typedef map<string, mspUIObject*>::iterator iterator;

		mspUI() 
        {
     		for (int i = 0; i < MULTI_SIZE; i++) {
                fMultiTable[i] = 0;
            }
            fMultiIndex = fMultiControl = 0;
        }
		virtual ~mspUI()
		{
            clear();
   		}
      
		void addButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addCheckButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspCheckButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {   
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
    
        void openTabBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openHorizontalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openVerticalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void closeBox() {fControlsLevel.pop_back(); fDeclareTable.clear();}

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            if (strcmp(key,"multi") == 0) {
                int index = atoi(val);
                if (index >= 0 && index < MULTI_SIZE) {
                    fMultiTable[index] = zone;
                    fMultiControl++;
                } else {
                    post("Invalid multi index = %d", index);
                }
            }
            
            fDeclareTable[key] = val;
        }
        
        void setMultiValues(FAUSTFLOAT* multi, int buffer_size)
		{
            for (int read = 0; read < buffer_size; read++) {
                int write = (fMultiIndex + read) & (MULTI_SIZE - 1);
                if (fMultiTable[write]) {
                    *fMultiTable[write] = multi[read];
                }
            }
            fMultiIndex += buffer_size;
		}
        
        bool isMulti() { return fMultiControl > 0; }
    
        bool isValue(string name) 
        {
            return (fUITable1.count(name) || fUITable2.count(name));
        }
        bool isOutputValue(string name) 
        {
            return fUITable3.count(name);
        }
        bool isInputValue(string name) 
        {
            return fUITable2.count(name);
        }
        bool setValue(string name, FAUSTFLOAT f)
        {
            if (fUITable1.count(name)) {
                fUITable1[name]->setValue(f);
                return true;
            } else if (fUITable2.count(name)) {
                fUITable2[name]->setValue(f);
                return true;
            } else {
                return false;
            }
        }
		FAUSTFLOAT getOutputValue(string name) { return fUITable3[name]->getValue(); }
          
        iterator begin1()	{ return fUITable1.begin(); }
        iterator end1()		{ return fUITable1.end(); }
        
        iterator begin2()	{ return fUITable2.begin(); }
        iterator end2()		{ return fUITable2.end(); }

        int itemsCount() { return fUITable1.size(); }
        void clear() 
        { 
            iterator it;
            for (it = begin1(); it != end1(); it++) {
                delete (*it).second;
            }
            fUITable1.clear(); 
            fUITable2.clear(); 
        }
};

//--------------------------------------------------------------------------
static bool check_digit(const string& name)
{
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { return true; }
    }
    return false;
}

static int count_digit(const string& name)
{
    int count = 0;
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { count++; }
    }
    return count;
}

/*--------------------------------------------------------------------------*/
void faust_anything(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (ac < 0) return;
    
    bool res = false;
    string name = string((s)->s_name);
    
    // Check if no argument is there, consider it is a toggle message for a button
    if (ac == 0 && obj->m_dspUI->isValue(name)) {
        
        string name = string((s)->s_name);
        float off = 0.0f;
        float on = 1.0f;
        obj->m_dspUI->setValue(name, off);
        obj->m_dspUI->setValue(name, on);
        
        av[0].a_type = A_FLOAT;
        av[0].a_w.w_float = off;
        faust_anything(obj, s, 1, av);
        
        return;
    }
    
    // List of values
    if (check_digit(name)) {
        
        int ndigit = 0;
        int pos;
        
        for (pos = name.size() - 1; pos >= 0; pos--) {
            if (isdigit(name[pos]) || name[pos] == ' ') {
                ndigit++;
            } else {
                break;
            }
        }
        pos++;
        
        string prefix = name.substr(0, pos);
        string num_base = name.substr(pos);
        int num = atoi(num_base.c_str());
        
        int i;
        t_atom* ap;
       
        // Increment ap each time to get to the next atom
        for (i = 0, ap = av; i < ac; i++, ap++) {
            float value;
            switch (atom_gettype(ap)) {
                case A_LONG: 
                    value = (float)ap[0].a_w.w_long;
                    break;
                
                case A_FLOAT:
                    value = ap[0].a_w.w_float;
                    break;
                    
                default:
                    post("Invalid argument in parameter setting"); 
                    return;         
            }
            
            stringstream num_val;
            num_val << num + i;
            char param_name[256];
            
            switch (ndigit - count_digit(num_val.str())) {
                case 0: 
                    sprintf(param_name, "%s%s", prefix.c_str(), num_val.str().c_str());
                    break;
                case 1: 
                    sprintf(param_name, "%s %s", prefix.c_str(), num_val.str().c_str());
                    break;
                case 2: 
                    sprintf(param_name, "%s  %s", prefix.c_str(), num_val.str().c_str());
                    break;
            }
            
            // Try special naming scheme for list of parameters
            res = obj->m_dspUI->setValue(param_name, value); 
            
            // Otherwise try standard name
            if (!res) {
                res = obj->m_dspUI->setValue(name, value);
            }
            
            if (!res) {
                post("Unknown parameter : %s", (s)->s_name);
            }
        }
    } else {
        // Standard parameter name
        float value = (av[0].a_type == A_LONG) ? (float)av[0].a_w.w_long : av[0].a_w.w_float;
        res = obj->m_dspUI->setValue(name, value);
    }
    
    if (!res) {
        post("Unknown parameter : %s", (s)->s_name);
    }
}

/*--------------------------------------------------------------------------*/
void faust_polyphony(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (systhread_mutex_lock(obj->m_mutex) == MAX_ERR_NONE) {
        // Delete old
        delete obj->m_dsp;
        obj->m_dspUI->clear();
        mydsp_poly* dsp_poly = NULL;
        // Allocate new one
        if (av[0].a_w.w_long > 0) {
            post("polyphonic DSP voices = %d", av[0].a_w.w_long);
            dsp_poly = new mydsp_poly(new mydsp(), av[0].a_w.w_long, true, true);
        #ifdef POLY2
            obj->m_dsp = new dsp_sequencer(dsp_poly, new effect());
        #else
            obj->m_dsp = dsp_poly;
        #endif
        } else {
            obj->m_dsp = new mydsp();
            post("monophonic DSP");
        }
        // Initialize User Interface (here connnection with controls)
        obj->m_dsp->buildUserInterface(obj->m_dspUI);
    #ifdef MIDICTRL
        obj->m_midiHandler->addMidiIn(dsp_poly);
        obj->m_dsp->buildUserInterface(obj->m_midiUI);
    #endif
        // Initialize at the system's sampling rate
        obj->m_dsp->init(long(sys_getsr()));
        
        // Prepare JSON
        faust_make_json(obj);
        
        // Send JSON to JS script
        faust_create_jsui(obj);
        
        systhread_mutex_unlock(obj->m_mutex);
    } else {
        post("Mutex lock cannot be taken...");
    }
}

/*--------------------------------------------------------------------------*/
#ifdef MIDICTRL
void faust_midievent(t_faust* obj, t_symbol* s, short ac, t_atom* av) 
{
    if (ac > 0) {
        int type = (int)av[0].a_w.w_long & 0xf0;
        int channel = (int)av[0].a_w.w_long & 0x0f;
                
        if (ac == 1) {
            obj->m_midiHandler->handleSync(0.0, av[0].a_w.w_long);
        } else if (ac == 2) {
            obj->m_midiHandler->handleData1(0.0, type, channel, av[1].a_w.w_long);
        } else if (ac == 3) {
            obj->m_midiHandler->handleData2(0.0, type, channel, av[1].a_w.w_long, av[2].a_w.w_long);
        }
    }
}
#endif

/*--------------------------------------------------------------------------*/
void faust_create_jsui(t_faust* x)
{
    t_object *patcher, *box, *obj;
    object_obex_lookup((t_object*)x, gensym("#P"), &patcher);
    
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        // Notify JSON
        if (obj && strcmp(object_classname(obj)->s_name, "js") == 0) {
            t_atom json;
            atom_setsym(&json, gensym(x->m_json));
            object_method_typed(obj, gensym("anything"), 1, &json, 0);
        }
    }
        
    // Keep all outputs
    x->m_output_table.clear();
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        t_symbol* scriptingname = jbox_get_varname(obj); // scripting name
        // Keep control outputs
        if (scriptingname && x->m_dspUI->isOutputValue(scriptingname->s_name)) {
            x->m_output_table[scriptingname->s_name].push_back(obj);
        }
    }
}

void faust_update_outputs(t_faust* x)
{
    map<string, vector<t_object*> >::iterator it1;
    vector<t_object*>::iterator it2;
    for (it1 = x->m_output_table.begin(); it1 != x->m_output_table.end(); it1++) {
        FAUSTFLOAT value = x->m_dspUI->getOutputValue((*it1).first);
        if (value != NAN) {
            t_atom at_value;
            atom_setfloat(&at_value, value);
            for (it2 = (*it1).second.begin(); it2 != (*it1).second.end(); it2++) {
                object_method_typed((*it2), gensym("float"), 1, &at_value, 0);
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_make_json(t_faust* x)
{
    // Prepare JSON
    if (x->m_json) free(x->m_json);
    JSONUI builder(x->m_dsp->getNumInputs(), x->m_dsp->getNumOutputs());
    x->m_dsp->metadata(&builder);
    x->m_dsp->buildUserInterface(&builder);
    x->m_json = strdup(builder.JSON().c_str());
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    bool midi_sync = false;
    int nvoices = 0;
    mydsp_poly* dsp_poly = NULL;
    
    mydsp* tmp_dsp = new mydsp();
    MidiMeta::analyse(tmp_dsp, midi_sync, nvoices);
    delete tmp_dsp;
    
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_json = 0;
    x->m_mute = false;
    
#ifdef MIDICTRL
    x->m_midiHandler = new midi_handler();
    x->m_midiUI = new MidiUI(x->m_midiHandler);
#endif
    
    if (nvoices > 0) {
        post("polyphonic DSP voices = %d", nvoices);
        dsp_poly = new mydsp_poly(new mydsp(), nvoices, true, true);
    #ifdef POLY2
        x->m_dsp = new dsp_sequencer(dsp_poly, new effect());
    #else
        x->m_dsp = dsp_poly;
    #endif
        
    #ifdef MIDICTRL
        x->m_midiHandler->addMidiIn(dsp_poly);
        x->m_dsp->buildUserInterface(x->m_midiUI);
    #endif
    } else {
        post("monophonic DSP");
        x->m_dsp = new mydsp();
    }
    
    x->m_Inputs = x->m_dsp->getNumInputs();
    x->m_Outputs = x->m_dsp->getNumOutputs();
   
    x->m_dspUI = new mspUI();

    x->m_dsp->init(long(sys_getsr()));
    x->m_dsp->buildUserInterface(x->m_dspUI);
    
    t_max_err err = systhread_mutex_new(&x->m_mutex, SYSTHREAD_MUTEX_NORMAL);
    if (err != MAX_ERR_NONE) {
        post("Cannot allocate mutex...");
    }
    
    // Prepare JSON
    faust_make_json(x);
    
    int num_input;
    
    if (x->m_dspUI->isMulti()) {
        num_input = x->m_dsp->getNumInputs() + 1;
    } else {
        num_input = x->m_dsp->getNumInputs();
    }
    
    x->m_args = (void**)calloc((num_input + x->m_dsp->getNumOutputs()) + 2, sizeof(void*));
    /* Multi in */
    dsp_setup((t_pxobject*)x, num_input);

    /* Multi out */
    for (int i = 0; i< x->m_dsp->getNumOutputs(); i++) {
        outlet_new((t_pxobject*)x, (char*)"signal");
    }

    ((t_pxobject*)x)->z_misc = Z_NO_INPLACE; // To assure input and output buffers are actually different
    
    // Send JSON to JS script
    faust_create_jsui(x);
    return x;
}

/*--------------------------------------------------------------------------*/
void faust_dblclick(t_faust* x, long inlet)
{
    post((char*)"------------------");
    for (mspUI::iterator it = x->m_dspUI->begin1(); it != x->m_dspUI->end1(); ++it) {
        char param[1024];
        it->second->toString(param);
        post(param);
    }
}

/*--------------------------------------------------------------------------*/
//11/13/2015 : faust_assist is actually called at each click in the patcher... to we now use 'faust_dblclick' to display the parameters...
void faust_assist(t_faust* x, void* b, long msg, long a, char* dst)
{
    if (msg == ASSIST_INLET) {
        if (a == 0) {
            if (x->m_dsp->getNumInputs() == 0) {
                sprintf(dst, "(signal) : Unused Input");
            } else {
                sprintf(dst, "(signal) : Audio Input %ld", (a+1));
			}
            /*
			post((char*)"------------------");
			for (mspUI::iterator it = x->m_dspUI->begin1(); it != x->m_dspUI->end1(); ++it) {
				char param[1024];
				it->second->toString(param);
				post(param);
			}
            */
        } else if (a < x->m_dsp->getNumInputs()) {
            sprintf(dst, "(signal) : Audio Input %ld", (a+1));
        }
    } else if (msg == ASSIST_OUTLET) {
        sprintf(dst, "(signal) : Audio Output %ld", (a+1));
    }
}

/*--------------------------------------------------------------------------*/
void faust_mute(t_faust* obj, t_symbol* s, short ac, t_atom* at)
{
    if (atom_gettype(at) == A_LONG) {
        obj->m_mute = atom_getlong(at);
    }
}

/*--------------------------------------------------------------------------*/
void faust_free(t_faust* x)
{
	dsp_free((t_pxobject*)x);
	delete x->m_dsp;
	delete x->m_dspUI;
	if (x->m_args) free(x->m_args);
    if (x->m_json) free(x->m_json);
    systhread_mutex_free(x->m_mutex);
#ifdef MIDICTRL
    delete x->m_midiHandler;
    delete x->m_midiUI;
#endif
}

/*--------------------------------------------------------------------------*/
void faust_perform64(t_faust* x, t_object* dsp64, double** ins, long numins, double** outs, long numouts, long sampleframes, long flags, void* userparam)
{
    AVOIDDENORMALS;
    if (!x->m_mute && systhread_mutex_trylock(x->m_mutex) == MAX_ERR_NONE) {
        if (x->m_dsp) {
            if (x->m_dspUI->isMulti()) {
                x->m_dspUI->setMultiValues(ins[0], sampleframes);
                x->m_dsp->compute(sampleframes, ++ins, outs);
            } else {
                x->m_dsp->compute(sampleframes, ins, outs);
            }
            faust_update_outputs(x);
        }
    #ifdef MIDICTRL
        GUI::updateAllGuis();
    #endif
         systhread_mutex_unlock(x->m_mutex);
    } else {
        // Write null buffers to outs
        for (int i = 0; i < numouts; i++) {
             memset(outs[i], 0, sizeof(double) * sampleframes);
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_dsp64(t_faust* x, t_object* dsp64, short* count, double samplerate, long maxvectorsize, long flags)
{
    object_method(dsp64, gensym("dsp_add64"), x, faust_perform64, 0, NULL);
}

/*--------------------------------------------------------------------------*/
extern "C" int main(void)
{
	setup((t_messlist**)&faust_class, (method)faust_new, (method)faust_free,
		(short)sizeof(t_faust), 0L, A_DEFFLOAT, 0);

    dsp* tmp_dsp = new mydsp();
    mspUI m_dspUI;
    tmp_dsp->buildUserInterface(&m_dspUI);

    // 03/11/14 : use 'anything' to handle all parameter changes
    addmess((method)faust_anything, (char*)"anything", A_GIMME, 0);
    addmess((method)faust_polyphony, (char*)"polyphony", A_GIMME, 0);
#ifdef MIDICTRL
    addmess((method)faust_midievent, (char*)"midievent", A_GIMME, 0);
#endif
    addmess((method)faust_dsp64, (char*)"dsp64", A_CANT, 0);
    addmess((method)faust_dblclick, (char*)"dblclick", A_CANT, 0);
    addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
    dsp_initclass();

    post((char*)"Faust DSP object v%s (sample = 64 bits code = %s)", EXTERNAL_VERSION, getCodeSize());
    post((char*)"Copyright (c) 2012-2017 Grame");
    Max_Meta1 meta1;
    tmp_dsp->metadata(&meta1);
    if (meta1.fCount > 0) {
        Max_Meta2 meta2;
        post("------------------------------");
        tmp_dsp->metadata(&meta2);
        post("------------------------------");
    }
    
    delete(tmp_dsp);
    return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/




