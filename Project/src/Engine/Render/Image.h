/* Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _IMAGE_LOADER_H
#define _IMAGE_LOADER_H

#include <assert.h>
#include <fstream>

using namespace std;

//Represents an image
class Image {
    public:
        Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {}
        ~Image() { delete[] pixels; }
        
        /* An array of the form (R1, G1, B1, R2, G2, B2, ...) indicating the
         * color of each pixel in image.  Color components range from 0 to 255.
         * The array starts the bottom-left pixel, then moves right to the end
         * of the row, then moves up to the next column, and so on.  This is the
         * format in which OpenGL likes images.
         */
        char* pixels;
        int width;
        int height;

        //Reads the next four bytes as an integer, using little-endian form
        
};


//Just like auto_ptr, but for arrays
template<class T>
class auto_array {
    private:
        T* array;
        mutable bool isReleased;
    public:
        explicit auto_array(T* array_ = NULL) :
            array(array_), isReleased(false) {
        }
        
        auto_array(const auto_array<T> &aarray) {
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }
        
        ~auto_array() {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
        }
        
        T* get() const {
            return array;
        }
        
        T &operator*() const {
            return *array;
        }
        
        void operator=(const auto_array<T> &aarray) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }
        
        T* operator->() const {
            return array;
        }
        
        T* release() {
            isReleased = true;
            return array;
        }
        
        void reset(T* array_ = NULL) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = array_;
        }
        
        T* operator+(int i) {
            return array + i;
        }
        
        T &operator[](int i) {
            return array[i];
        }
};

#endif