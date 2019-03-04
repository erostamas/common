
#include "C.h"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"


int main() {
    std::shared_ptr<avro::OutputStream> out = avro::memoryOutputStream();
    avro::EncoderPtr e = avro::binaryEncoder();
    e->init(*out);
    C c1;
    c1.a = 9999999999999;
    c1.b = 2;
    avro::encode(*e, c1);

    std::shared_ptr<avro::InputStream> in = avro::memoryInputStream(*out);
    avro::DecoderPtr d = avro::binaryDecoder();
    d->init(*in);

    C c2;
    avro::decode(*d, c2);
    std::cout << '(' << c2.a << ", " << c2.b << ')' << std::endl;
    return 0;
}
