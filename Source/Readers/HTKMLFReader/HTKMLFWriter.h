//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//
// HTKMLFReader.h - Include file for the MTK and MLF format of features and samples
//
#pragma once
#include "DataWriter.h"
#include "ScriptableObjects.h"
#include <map>
#include <vector>

namespace Microsoft { namespace MSR { namespace CNTK {

template <class ElemType>
class HTKMLFWriter : public IDataWriter<ElemType>
{
private:
    std::vector<size_t> outputDims;
    std::vector<std::vector<std::wstring>> outputFiles;

    std::vector<size_t> udims;
    std::map<std::wstring, size_t> outputNameToIdMap;
    std::map<std::wstring, size_t> outputNameToDimMap;
    std::map<std::wstring, size_t> outputNameToTypeMap;
    unsigned int sampPeriod;
    size_t outputFileIndex;
    void Save(std::wstring& outputFile, Matrix<ElemType>& outputData);
    ElemType* m_tempArray;
    size_t m_tempArraySize;

    enum OutputTypes
    {
        outputReal,
        outputCategory,
    };

public:
    using LabelType = typename IDataWriter<ElemType>::LabelType;
    using LabelIdType = typename IDataWriter<ElemType>::LabelIdType;
    template <class ConfigRecordType>
    void InitFromConfig(const ConfigRecordType& writerConfig);
    virtual void Init(const ConfigParameters& config)
    {
        InitFromConfig(config);
    }
    virtual void Init(const ScriptableObjects::IConfigRecord& config)
    {
        InitFromConfig(config);
    }
    virtual void Destroy();
    virtual void GetSections(std::map<std::wstring, SectionType, nocase_compare>& sections);
    virtual bool SaveData(size_t recordStart, const std::map<std::wstring, void*, nocase_compare>& matrices, size_t numRecords, size_t datasetSize, size_t byteVariableSized);
    virtual void SaveMapping(std::wstring saveId, const std::map<LabelIdType, LabelType>& labelMapping);
};
} } }
