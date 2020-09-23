module.exports = class InstructionManager {
  constructor(file_info) {
    this.inst_map = {};

    for (const file_name in file_info) {
      let file = file_info[file_name];
      if (file.path && file.path.startsWith('/X86-64 명령어 레퍼런스')) {
        this.inst_map[file_name] = file;
      }
    }
  }

  getInstruction(inst) {
    if(/^[0-9]+$/.test(inst)) {
      return null;
    }
    
    inst = inst.toLowerCase();
    return this.inst_map[inst];
  }
}