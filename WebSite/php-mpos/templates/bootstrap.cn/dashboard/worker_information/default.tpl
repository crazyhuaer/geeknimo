{if !$DISABLED_DASHBOARD and !$DISABLED_DASHBOARD_API}
  <div class="col-lg-4">
    <div class="panel panel-info">
      <div class="panel-heading">
        <h4 class="panel-title"><i class="fa fa-desktop fa-fw"></i> 矿 工 信 息</h4>
      </div>
      <div class="panel-body no-padding table-responsive">
        <table class="table table-bordered table-hover table-striped"> 
         <thead>
          <tr>
            <th>矿工号</th>
            <th>算力</th>
            <th>难度</th>
          </tr>
          </thead>
          <tbody id="b-workers">
            <td colspan="3" class="text-center">暂无矿工信息</td>
          </tbody>
        </table>
      </div>
    </div>
  </div>
{/if}
