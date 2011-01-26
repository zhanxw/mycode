#!/usr/bin/python
import sys, os, os.path, re

def usage():
    print("%s old.vcf chain_file new.vcf unlifted.vcf" % sys.argv[0] )

def checkFileExist(fileName):
    if (os.path.exists(fileName) != True):
        print >> sys.stderr, fileName, "does not exists!"
        sys.exit(1)
if __name__ == '__main__':
    if (len(sys.argv) != 5):
        usage()
        sys.exit(1)

    oldVCFFileName, chainFileName, newVCFFileName, unliftedVCFFileName = sys.argv[1:]
    map(checkFileExist, [oldVCFFileName, chainFileName])
    checkFileExist("liftOver")
    
    # convert VCF to BED format
    print "Convert %s to BED format" % oldVCFFileName
    oldBEDFileName = oldVCFFileName + ".bed"
    fout = open(oldBEDFileName, "wt")
                
    for line in open(oldVCFFileName):
        if re.match(r'^#', line): continue
        line = line.strip().split()
        if re.match(r'^chr', line[0]): # UCSC liftOver require chrXX style chromosome name
            chrom = line[0].lower()
        else:
            chrom = "chr%s" % line[0].lower()
        start = str(int(line[1]) - 1)
        end = (line[1])
        fout.write('\t'.join([chrom, start, end]))
        fout.write('\n')
    fout.close()
    newBEDFileName = newVCFFileName+".bed"
    unliftedBEDFileName = unliftedVCFFileName+".bed"
    cmd = " ".join(["./liftOver ", oldBEDFileName, chainFileName, newBEDFileName, unliftedBEDFileName])
    print "Running: ", cmd
    os.system(cmd)

    # store unlifted BED record to a Python set
    unliftedSet = set()
    for line in open(unliftedBEDFileName):
        if re.match(r'^#', line):
            continue
        line = line.strip().split()
        record = ':'.join([line[0], line[2]]) # store chr1:11111, 1-based
        unliftedSet.add(record)
    print len(unliftedSet), " lines are not lifted"
    
    # output results
    print "Output lifted results: %s and %s ... " % (newVCFFileName, unliftedVCFFileName)
    fout = open(newVCFFileName, 'wt')
    fUnlifted = open(unliftedVCFFileName, 'wt')
    fin = open(newBEDFileName)
    for line in open(oldVCFFileName):
        if re.match(r'^#', line): # write head part of VCF
            fout.write(line)
            continue
        record = line.strip().split()
        if re.match(r'^chr', record[0]):
            chrom = record[0].lower()
        else:
            chrom = "chr%s" % record[0].lower()
        pos = record[1]
        rec = ":".join([chrom, pos])
        if (rec in unliftedSet):
            fUnlifted.write(line)
        else:
            bed = fin.readline().strip().split()
            fout.write('\t'.join([bed[0], bed[2]]))
            fout.write('\t')
            fout.write('\t'.join(record[2:]))
            fout.write('\n')
    fout.close()
    fUnlifted.close()
    fin.close()
    
