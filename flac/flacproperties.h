/***************************************************************************
    copyright            : (C) 2003 by Allan Sandfeld Jensen
    email                : kde@carewolf.org
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it  under the terms of the GNU Lesser General Public License version  *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *
 *   USA                                                                   *
 ***************************************************************************/

#ifndef TAGLIB_FLACPROPERTIES_H
#define TAGLIB_FLACPROPERTIES_H

#include <audioproperties.h>

namespace TagLib {

  namespace FLAC {

    class File;

    //! An implementation of audio property reading for FLAC

    /*!
     * This reads the data from an FLAC stream found in the AudioProperties
     * API.
     */

    class Properties : public AudioProperties
    {
    public:
      /*!
       * Create an instance of FLAC::Properties with the data read from the
       * ByteVector \a data.
       */
      Properties(ByteVector data, long streamLength, ReadStyle style = Average);

      /*!
       * Create an instance of FLAC::Properties with the data read from the
       * FLAC::File \a file.
       */
      Properties(File *file, ReadStyle style = Average); // BIC: remove

      /*!
       * Destroys this FLAC::Properties instance.
       */
      virtual ~Properties();

      // Reimplementations.

      virtual int length() const;
      virtual int bitrate() const;
      virtual int sampleRate() const;
      virtual int channels() const;

      /*!
       * Returns the sample width as read from the FLAC identification
       * header.
       */
      int sampleWidth() const;

    private:
      void read();

      class PropertiesPrivate;
      PropertiesPrivate *d;
    };
  }
}

#endif
