#include <sstream>
#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

struct C {
	int a = 0;
	int b = 0;
};

template<> struct avro::codec_traits<C> {
    static void encode(Encoder& e, const C& c) {
        avro::encode(e, c.a);
        avro::encode(e, c.b);
    }
    static void decode(Decoder& d, C& c) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, c.a);
                    break;
                case 1:
                    avro::decode(d, c.b);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, c.a);
            avro::decode(d, c.b);
        }
    }
};
