//
// Created by Misra, Shakti on 22/08/20.
//

#ifndef SALT_DTOS_HPP
#define SALT_DTOS_HPP
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  Data Transfer Object. Object containing fields only.
 *  Used in API for serialization/deserialization and validation
 */
class MyDto : public oatpp::DTO {

    DTO_INIT(MyDto, DTO)

    DTO_FIELD(Int32, statusCode);
    DTO_FIELD(String, message);

};

#include OATPP_CODEGEN_END(DTO)

#endif //SALT_DTOS_HPP
